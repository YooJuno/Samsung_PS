#include <iostream>
#include <cstring>

using namespace std;


enum Direction
{
    STOP,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Pos
{
    int y;
    int x;
};

struct Cluster
{
    Pos pos;
    int num;
    int direction;
};

struct Cell
{
    int id;
    int max;
};

void Move(Cluster* cl)
{
    if(cl->direction == UP) 
        cl->pos.y--;
    else if(cl->direction == DOWN) 
        cl->pos.y++;
    else if(cl->direction == RIGHT) 
        cl->pos.x++;
    else if(cl->direction == LEFT) 
        cl->pos.x--;
    else 
        return;
}

int getInversedDirection(int di)
{
    if(di == UP) 
        return DOWN;
    else if(di == DOWN) 
        return UP;
    else if(di == LEFT) 
        return RIGHT;
    else if(di == RIGHT) 
        return LEFT;
    else 
        return -1;
}

int main()
{
    freopen("sample_input.txt", "r", stdin);

    int T; cin >> T;

    for (auto test_case = 1; test_case <= T; test_case++)
    {
        int sum = 0;

        int N; cin >> N; // 변 길이
        int M; cin >> M; // 격리 시간
        int K; cin >> K; // 군집 갯 수

        Cluster cluster[K];
        for(int i=0; i<K; i++)
        {
            cin >> cluster[i].pos.y >> cluster[i].pos.x; // 좌표 입력
            cin >> cluster[i].num; // 미생물 수
            cin >> cluster[i].direction; // 초기 방향
        }

        Cell Map[N][N]; // cluster idx, max_num
        memset(Map, -1, sizeof(Map));

        for(int time=0; time<M; time++)
        {
            for(int i=0; i<K; i++)
            { 
                if(cluster[i].num == 0) 
                    continue;
                
                if(Map[cluster[i].pos.y][cluster[i].pos.x].id == i)
                {
                    Map[cluster[i].pos.y][cluster[i].pos.x].id = -1; // id
                    Map[cluster[i].pos.y][cluster[i].pos.x].max = -1; // maxNum
                }
                Move(&cluster[i]);
                
                // 빨간 약품에 들어갔을 때
                if(cluster[i].pos.y == 0 || cluster[i].pos.y == N-1 || cluster[i].pos.x == 0 || cluster[i].pos.x == N-1)
                {
                    // 군집 반감
                    cluster[i].num /= 2;

                    // 방향 반대 전환
                    cluster[i].direction = getInversedDirection(cluster[i].direction);
                }

                // 아무도 없을 때 || 아직 이동하지 않은 군집일 때
                if(Map[cluster[i].pos.y][cluster[i].pos.x].id == -1 || Map[cluster[i].pos.y][cluster[i].pos.x].id > i)
                {
                    // id 초기화
                    Map[cluster[i].pos.y][cluster[i].pos.x].id = i;

                    // max 초기화
                    Map[cluster[i].pos.y][cluster[i].pos.x].max = cluster[i].num;
                }

                // 누가 있을 때 && 같은 타임에서 나보다 먼저 이동해 왔을 때
                else
                {
                    // 새로 들어온 군집이 더 클 때
                    if(Map[cluster[i].pos.y][cluster[i].pos.x].max < cluster[i].num)
                    {
                        // 해당 좌표의 max값 갱신(흡수 하기 전에 갱신해야함)
                        Map[cluster[i].pos.y][cluster[i].pos.x].max = cluster[i].num;
                        
                        // 기존 군집 흡수(해당 좌표의 cluster id 갱신 전에 해야함.)
                        cluster[i].num += cluster[Map[cluster[i].pos.y][cluster[i].pos.x].id].num;
                        
                        // 기존 군집 삭제(해당 좌표의 cluster id 갱신 전에 해야함.)
                        cluster[Map[cluster[i].pos.y][cluster[i].pos.x].id].num = 0;

                        // 해당 좌표의 cluster id를 현재 idx로 갱신
                        Map[cluster[i].pos.y][cluster[i].pos.x].id = i;
                    }
                    // 기존 군집이 더 클 때
                    else    
                    {
                        // 기존 군집 흡수
                        cluster[Map[cluster[i].pos.y][cluster[i].pos.x].id].num += cluster[i].num;

                        // 새로 들어온 군집 삭제
                        cluster[i].num = 0;
                    }
                }
            }
        }

        for(int i=0; i<K; i++) 
            sum += cluster[i].num;

        cout << '#' << test_case << ' ' << sum << endl;
    }
    return 0;
}