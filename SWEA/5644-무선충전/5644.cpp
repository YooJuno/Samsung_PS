#include <iostream>

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
    int y;
    int x;
};

struct BatteryCharger
{
    Pos pos;
    int c;
    int p;
};

auto calcDistBetween(Pos pos1[2], Pos pos2) -> int
{
    return abs(pos1.x-pos2.x) + abs(pos1.y-pos2.y);
}

void Move(Pos* pos, int direction)
{
    pos
    if(direction==UP)   
        pos->y--;
    else if(direction==RIGHT)   
        pos->x++;
    else if(direction==dOWN)   
        pos->y--;
    else if(direction==LEFT)   
        pos->x--;
    else
        return -1;
}

auto main() -> int
{
    // freopen("sample_input.txt", "r", stdin);

    int T; cin >> T;
    
    for (auto test_case = 1; test_case <= T; test_case++)
    // for (auto test_case = 1; test_case <= 1; test_case++)
    {
        int sum = 0;

        int M; cin >> M; // 총 이동 시간
        int A; cin >> A; // BC의 갯 수
        
        int route[2][M];
        for(int i=0; i<2; i++)
            for(int j=0; j<M; j++)
                cint >> route[i][j];
        
        BatteryCharger bc[A];
        for(int i=0; i<A; i++)
        {
            cin >> bc[i].pos.y >> bc[i].pos.x; // battery charger의 좌표
            cin >> bc[i].c; // battery charger의 coverage
            cin >> bc[i].p; // battery charger의 power

            bc[i].pos.y--;
            bc[i].pos.x--;
        }

        Pos user[2];
        user[0] = {0,0};
        user[1] = {9,9};

        Move(user, time);



        
        cout << '#' << test_case << ' ' << sum << endl;
    }

    return 0;
}