#include <iostream>

using namespace std;

struct Cell
{
    int y;
    int x;
};      

int main(int argc, const char** argv) 
{
    int T; cin >> T;
    for (int test_case = 0; test_case < T; test_case++)
    {
        int sum = 0;

        int M; cin >> M;
        int A; cin >> A;

        int routeA[M];
        int routeB[M];

        for (int i = 0; i < M; i++)
            cin >> routeA[i];
        for (int i = 0; i < M; i++)
            cin >> routeB[i];

        


        std::cout << sum << std::endl;
    }
    return 0;
}