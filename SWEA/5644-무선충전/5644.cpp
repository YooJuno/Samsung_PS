#include <iostream>
#include <cstring>
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

struct Pos
{
    int x;
    int y;
};

auto calcDistBetween(int x1, int y1, int x2, int y2) -> int
{
    return abs(x1-x2) + abs(y1-y2);
}

class BatteryCharger
{
public:
    BatteryCharger()
    {
        cin >> pos.x >> pos.y >> c >> p;
        pos.x--;
        pos.y--;
        memset(boundary, false, sizeof(boundary));
    }

    void setBoundary()
    {
        for(auto i = max(0, pos.y-c); i <= min(9, pos.y+c); i++) // y
        {
            for(auto j = max(0, pos.x-c); j <= min(9, pos.x+c); j++) // x
            {
                if(calcDistBetween(pos.x, pos.y, j, i) <= c)
                {
                    boundary[i][j] = true;
                }
            }
        }

    }

    void printBatteryArea()
    {
        for(auto i=0; i<10; i++)
        {
            for(auto j=0; j<10; j++)
            {
                cout << boundary[i][j] << ' ';
            }
            cout << endl;
        }
    }

    auto isInBoundary(Pos posP) -> bool
    {
        return boundary[posP.y][posP.x];
    }

    auto getP() -> int
    {
        return p;
    }

    void addBoundaryTo(vector<int> map[10][10])
    {
        for(auto i=0; i<10; i++)
        {
            for(auto j=0; j<10; j++)
            {
                if(boundary[i][j] == true)
                    map[i][j].emplace_back(p);
            }
        }
    }

private:
    Pos pos;
    int c; // 1 ≤ C ≤ 4
    int p; // 10 ≤ P ≤ 500
    bool boundary[10][10];
};

class Player
{
public:
    Player(int M, int x, int y)
    {
        routeDir = new int[M];
        for(int i=0; i<M; i++) 
            cin >> routeDir[i];

        pos.x = x;
        pos.y = y;
    }

    void Move(int t)
    {
        if(routeDir[t] == UP) pos.y--;
        else if(routeDir[t] == RIGHT) pos.x++;
        else if(routeDir[t] == DOWN) pos.y++;
        else if(routeDir[t] == LEFT) pos.x--;
        else return;
    }

    auto getPos() -> Pos
    {   
        return pos;
    }

private:
    Pos pos;
    int* routeDir;
};


int main()
{
    // freopen("sample_input.txt", "r", stdin);

    int T; cin >> T;

    for (auto test_case = 1; test_case <= T; test_case++)
    // for (auto test_case = 1; test_case <= 1; test_case++)
    {
        auto sum = 0;
        int M; // (20 ≤ M ≤ 100)
        int A; // (1 ≤ A ≤ 8)
        cin >> M >> A;

        Player pA(M, 0, 0);
        Player pB(M, 9, 9);

        BatteryCharger bc[A]; // 클래스 배열 생성

        ////////////////////////////////////////////
        ///////////////// 입력 완료 ////////////////
        ///////////////////////////////////////////
        
        vector<int> map[10][10];

        for(auto i=0; i<A; i++)
        {
            bc[i].setBoundary();
            bc[i].addBoundaryTo(map);
        }

        for(auto i=0; i<10; i++)
        {
            for(auto j=0; j<10; j++)
            {
                sort(map[i][j].begin(), map[i][j].end(), [](int a, int b){ return a > b;});
            }
        }

        // Timer Start
        for(auto t=0; t<=M; t++)
        {
            auto tempSum = 0;
            // 현재 위치에 있는 모든 플레이어가 어떤떤 배터리 차저 영역에 있으면
            if(map[pA.getPos().y][pA.getPos().x].size() > 0 && map[pB.getPos().y][pB.getPos().x].size() > 0)
            {
                bool isDuplicated = false; 
                for(int i=0; i<A; i++)
                {
                    // 같은 배터리차저에 있으면
                    if(bc[i].isInBoundary(pA.getPos()) && bc[i].isInBoundary(pB.getPos()))
                    {
                        isDuplicated = true;
                        // 서로 이 곳에만 걸쳐 있으면
                        if(map[pA.getPos().y][pA.getPos().x].size() == 1 && map[pB.getPos().y][pB.getPos().x].size() == 1)
                        {
                            if(tempSum < bc[i].getP())
                            {
                                tempSum = bc[i].getP();
                            }
                        }
                        // 어느 하나라도 다른 곳에도 걸쳐 있으면
                        else
                        {
                            for(auto j=0; j<A; j++)
                            {
                                if(i!=j)
                                {
                                    if(bc[j].isInBoundary(pA.getPos()) || bc[j].isInBoundary(pB.getPos()))
                                    {
                                        if(tempSum < bc[i].getP() + bc[j].getP())
                                        {
                                            tempSum = bc[i].getP() + bc[j].getP();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                // 서로 겹쳐 있지 않다면 현재 위치에서 제일 파워가 쎈 값을 썸에 더해줌.
                if(isDuplicated == false)
                {
                    if(tempSum < map[pA.getPos().y][pA.getPos().x][0] + map[pB.getPos().y][pB.getPos().x][0])
                    {
                        tempSum = map[pA.getPos().y][pA.getPos().x][0] + map[pB.getPos().y][pB.getPos().x][0];
                    }
                }
            }
            // 모든 플레이어가 배터리 차저 안에 있는 것은 아니라면(한 명이라도 있다면)
            else
            {
                if(map[pA.getPos().y][pA.getPos().x].size() > 0)
                {
                    tempSum = map[pA.getPos().y][pA.getPos().x][0];
                }
                if(map[pB.getPos().y][pB.getPos().x].size() > 0)
                {
                    tempSum = map[pB.getPos().y][pB.getPos().x][0];
                }
            }

            sum += tempSum;

            // 다음 턴을 위해 이동
            pA.Move(t);
            pB.Move(t);
        }

        cout << '#' << test_case << ' ' << sum << endl;
    }

    return 0;
}
