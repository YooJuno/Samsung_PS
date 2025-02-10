#include <iostream>

using namespace std;

enum Direction
{
    CLOCKWISE,
    COUNTER_CLOCKWISE
};

struct Magnet
{
    int idx;
    int direction;
};

bool polarities[4][8]; // 날 정보(0:N, 1:S)
Magnet rotations[21];

auto main() -> int
{
    freopen("sample_input.txt", "r", stdin);

    int T; cin >> T;
    for(auto test_case=1; test_case<=T; test_case++)
    {
        int K; cin >> K; // 자석을 회전시키는 횟수
        memset(polarities, 0, sizeof(polarities));
        for(auto i = 0; i < 4; i++)
        {
            for(auto j = 0; j < 8; j++)
            {
                cin >> polarities[i][j];
            }
        }

        for(auto i = 0; i < K; i++)
        {
            cin >> rotations[i].idx >> rotations[i].direction;
        }
        
        
        
        
        cout << '#' << test_case << ' ' << result << endl;
    }
    return 0;
}