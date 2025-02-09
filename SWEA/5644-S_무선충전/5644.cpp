#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum Direction
{
    STOP,
    UP,
    RIGHT,
    DOWN,
    LEFT
};

struct Player
{
    int x;
    int y;
    int idx;
};

struct Cell
{
    int p;
    int idx;
};

auto calcDist(int x1, int y1, int x2, int y2) -> int
{    
    return abs(x2-x1) + abs(y2-y1);
}

void Move(Player* p, int direction)
{
    if(direction == UP)
        p->y--;
    else if(direction == RIGHT)
        p->x++;
    else if(direction == DOWN)
        p->y++;
    else if(direction == LEFT)
        p->x--;
}

auto main() -> int
{
    // freopen("sample_input.txt", "r", stdin);

    int T; cin >> T;
    for(auto test_case=1; test_case<=T; test_case++)
    {
        int result = 0;
        
        int M; cin >> M; // 이동 시간
        int A; cin >> A; // BC의 갯 수
        
        int routeA[M];
        int routeB[M];
        for(auto i = 0; i < M; i++)
            cin >> routeA[i];
        for(auto i = 0; i < M; i++)
            cin >> routeB[i];
        
        vector<Cell> map[10][10];
        for(auto i = 0; i < A; i++)
        {   
            int x, y, c, p;
            cin >> x >> y >> c >> p;
            x--;
            y--;
            
            for(auto j = max(0, y-c); j <= min(9, y+c); j++)
            {
                for(auto k = max(0, x-c); k <= min(9, x+c); k++)
                {
                    if(calcDist(x, y, k, j) <= c)
                    {
                        map[j][k].push_back({p, i});
                    }
                }
            }
        }
        for(auto i = 0; i < 10; i++)
        {
            for(auto j = 0; j < 10; j++)
            {
                if(map[i][j].size() > 1)
                {
                    sort(map[i][j].begin(), map[i][j].end(), [](Cell x, Cell y){return x.p > y.p;});
                }
            }
        }
        
        Player playerA, playerB; 
        playerA.x = 0; playerA.y = 0;
        playerB.x = 9; playerB.y = 9;

        // Timer start
        for(auto time = 0; time <= M; time++)
        {
            // 둘 다 있는 곳에 최소 하나의 배터리 차저가 있을 때
            if(map[playerA.y][playerA.x].size() > 0 && map[playerB.y][playerB.x].size() > 0)
            {
                // 최고 높은 파워가 같은 배터리 차저일 때
                if(map[playerA.y][playerA.x][0].idx == map[playerB.y][playerB.x][0].idx)
                {
                    // 서로 단 하나의 배터리 차저에만 속해있을 때
                    if(map[playerA.y][playerA.x].size() == 1 && map[playerB.y][playerB.x].size() == 1)
                    {
                        // 파워를 서로 나눠 가짐.
                        result += map[playerA.y][playerA.x][0].p;
                    }
                    // A는 다수의, B는 하나의 배터리 차저에만 속해있을 때
                    else if(map[playerA.y][playerA.x].size() > 1 && map[playerB.y][playerB.x].size() == 1)
                    {
                        result += map[playerA.y][playerA.x][1].p;
                        result += map[playerB.y][playerB.x][0].p;
                    }
                    // B는 다수의 A는 하나의 배터리 차저에만 속해있을 때
                    else if(map[playerA.y][playerA.x].size() == 1 && map[playerB.y][playerB.x].size() > 1)
                    {
                        result += map[playerA.y][playerA.x][0].p;
                        result += map[playerB.y][playerB.x][1].p;
                    }
                    else if(map[playerA.y][playerA.x].size() > 1 && map[playerB.y][playerB.x].size() > 1)
                    {
                        result += map[playerA.y][playerA.x][0].p;
                        (map[playerA.y][playerA.x][1].p > map[playerB.y][playerB.x][1].p) ? result += map[playerA.y][playerA.x][1].p : result += map[playerB.y][playerB.x][1].p;
                    }
                }
                // 서로 있는 곳에 제일 높은 파워의 배터리 차저가 다른 것일 때. 
                else
                {
                    result += map[playerA.y][playerA.x][0].p;
                    result += map[playerB.y][playerB.x][0].p;
                }
            }
            else if(map[playerA.y][playerA.x].size() > 0 && map[playerB.y][playerB.x].size() == 0)
            {
                result += map[playerA.y][playerA.x][0].p;
            }
            else if(map[playerA.y][playerA.x].size() == 0 && map[playerB.y][playerB.x].size() > 0)
            {
                result += map[playerB.y][playerB.x][0].p;
            }

            Move(&playerA, routeA[time]);
            Move(&playerB, routeB[time]);
        }

        cout << '#' << test_case << ' ' << result << endl;
    }
    return 0;
}

