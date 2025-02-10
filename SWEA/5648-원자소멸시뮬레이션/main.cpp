#include <iostream>

using namespace std;

enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Cell 
{
    int x;
    int y;
    int direction;
    int K; // 보유 에너지
    bool isAlive;
};

void Move(Cell* cell)
{
    if(cell.direction == UP) cell.y++;
    if(cell.direction == DOWN) cell.y--;
    if(cell.direction == LEFT) cell.x--;
    if(cell.direction == RIGHT) cell.x++;
}

auto main() -> int
{
    freopen("sample_input.txt", "r", stdin);

    int T; cin >> T;
    for(auto test_case=1; test_case<=T; test_case++)
    {
        int sum = 0;
        
        int N; cin >> N; // 원자들의 수 (1 <= N <= 1000)
        Cell cells[N];
        for(auto i = 0; i < N; i++)
        {
            cin >> cells[i].x >> cells[i].y >> cells[i].direction >> cells[i].K;
            cells[i].isAlive = true;
        }
        
        // 종료조건?
        while(true)
        {
            for(auto i = 0; i < N; i++)
            {
                Move(&cells[i]);
            }

            // 
        }
        
        cout << '#' << test_case << ' ' << sum << endl;
    }
    return 0;
}