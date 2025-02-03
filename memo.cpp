#include <iostream>
using namespace std;

auto isStable(int map[][4]) -> bool
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(map[i][j] == 1)
            {
                if(map[i-1][j]==1 || map[i][j-1]==1 || map[i+1][j] == 1 || map[i][j+1] == 1)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

auto main() -> int
{
    int map[5][4];

    for(auto i=0; i<5; i++)
        for(auto j=0; j<4; j++)
            cin >> map[i][j];

    isStable(map) ? cout << "안정된 상태\n" : cout << "불안정한 상태\n";

    return 0;
}
