#include <iostream>

using namespace std;

enum Rotation
{
    CONTERCLOCKWISE = 0,
    CLOCKWISE=1
};

void recursive(bool magnet[4][8], int idx, bool rotate, bool goToLeft, bool goToRight, bool ns)
{
    // printf("idx : %d , rotate : %d , left  : %d , right : %d\n", idx, rotate, goToLeft, goToRight);
    if(idx == -1 || idx == 4) return;

    if((goToLeft && ns != magnet[idx][2]) || (goToRight && ns != magnet[idx][6]) || (goToLeft && goToRight))
    {
        // printf("Rotate!\n");
        if(rotate == CLOCKWISE)
        {
            bool temp = magnet[idx][7];
            for(auto i = 6; i >= 0; i--)
            {
                magnet[idx][i+1] = magnet[idx][i];
            }
            magnet[idx][0] = temp;
        }
        else
        {
            bool temp = magnet[idx][0];
            for(auto i = 1; i < 8; i++)
            {
                magnet[idx][i-1] = magnet[idx][i];
            }
            magnet[idx][7] = temp;
        }
    }


    if(goToLeft) recursive(magnet, idx-1, !rotate, 1, 0, magnet[idx][6]);
    if(goToRight) recursive(magnet, idx+1, !rotate, 0, 1, magnet[idx][2]);
}

auto main() -> int
{
    freopen("sample_input.txt", "r", stdin);

    int T; cin >> T;
    // for(auto test_case=1; test_case<=T; test_case++)
    for(auto test_case=1; test_case<=1; test_case++)
    {
        int result = 0;
        
        int K; cin >> K; // 1 - 4
        bool magnet[4][8]; // N:0   S:1
        for(auto i = 0; i < 4; i++)
        {
            for(auto j = 0; j < 8; j++)
            {
                cin >> magnet[i][j];
            }
        }

        for(auto i = 0; i < K; i++)
        {
            int magnetIdx; cin >> magnetIdx;
            int rotation; cin >> rotation; // 1:CLOCKWISE -1:COUNTER
            // printf("[magnetIdx:%d , rotate:%d]\n", magnetIdx-1, rotation);
            recursive(magnet, magnetIdx-1, (bool)(rotation+1), 1, 1, 0);
            
        }
        result = magnet[0][0] + magnet[1][0]*2 + magnet[2][0]*4 + magnet[3][0]*8;
        cout << '#' << test_case << ' ' << result << endl;
    }
    return 0;
}