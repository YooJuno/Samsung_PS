#include <iostream>

using namespace std;

enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Atom
{
    int x;
    int y;
    int direction;
    int k;
    bool isDead;
};

auto main() -> int
{
    freopen("sample_input.txt", "r", stdin);

    int T; cin >> T;
    for(auto test_case=1; test_case<=T; test_case++)
    {
        int result = 0;
        
        int N; cin >> N;
        Atom atom[N];
        for(auto i = 0; i < N; i++)
        {
            cin >> atom[i].x >> atom[i].y >> atom[i].direction >> atom[i].k;
        }

        while(true)
        {
            for(auto i = 0; i < N; i++)
            {
                if(atom[i].direction == UP) atom[i].y++;
                if(atom[i].direction == DOWN) atom[i].y--;
                if(atom[i].direction == LEFT) atom[i].x--;
                if(atom[i].direction == RIGHT) atom[i].x++;
                
            }
        }
        
        cout << '#' << test_case << ' ' << result << endl;
    }
    return 0;
}