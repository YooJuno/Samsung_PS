#include <iostream>
#include <cstring>
#include <unodered_map>

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
    bool isDead; // 죽었는지 
};

void Move(Cell* cell)
{
    if(cell->direction == UP) cell->y++;
    else if(cell->direction == DOWN) cell->y--;
    else if(cell->direction == LEFT) cell->x--;
    else if(cell->direction == RIGHT) cell->x++;
}

auto main() -> int
{
    freopen("sample_input.txt", "r", stdin);

    int T; cin >> T;

    for(int test_case=1; test_case<=T; test_case++)
    {
        int sum = 0;
        
        int N; cin >> N; // 원자들의 수 (1 <= N <= 1000)
        Cell cells[N];
        memset(cells, 0, sizeof(cells));
        
        for(auto i = 0; i < N; i++)
        {
            cin >> cells[i].x >> cells[i].y >> cells[i].direction >> cells[i].K;
        }
        
        int timer = 0;
        while(++timer)
        {
            
        }
        
        cout << '#' << test_case << ' ' << sum << endl;
    }
    
    return 0;
}