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

struct BatteryCharger
{
    int x;
    int y;
    int c;
    int p;
};



auto main() -> int
{
    freopen("sample_input.txt", "r", stdin);

    int T; cin >> T;
    for(auto test_case=1; test_case<=T; test_case++)
    {
        
        int M; cin >> M; // 이동 시간
        int A; cin >> A; // BC의 갯 수
        
        int routeA[M];
        int routeB[M];
        for(auto i = 0; i < M; i++)
        {
            cin >> routeA[i];
        }
        for(auto i = 0; i < M; i++)
        {
            cin >> routeB[i];
        }
        
        BatteryCharger bc[A];
        for(auto i = 0; i < A; i++)
        {   
            cin >> bc[i];
        }
        
        cout << '#' << test_case << ' ' << result << endl;
    }
    return 0;
}

