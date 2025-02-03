<<<<<<< HEAD
/*
////////// Do not remove //////////
코드 실행 : ctrl + opt(win) + N

*/

=======
>>>>>>> 0f1f0520a9794c3c2e08b76be2135dab47bc2194
#include <iostream>
using namespace std;

<<<<<<< HEAD
auto main() -> int
{
    int N;
    int K;
    cin >> N >> K;    

    int arr[N];
    for(int i=0; i<N; i++) cin >> arr[i];

    int cnt = 0;

    for(int i=0; i<N-2; i++)
    {
        for(int j=i+1; j<N-1; j++)
        {
            int sumIJ = arr[i] + arr[j];
            
            for(int k=j+1; k<N; k++)
            {
                if(sumIJ + arr[k] == K)
                {
                    cnt++;
=======
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
>>>>>>> 0f1f0520a9794c3c2e08b76be2135dab47bc2194
                }
            }
        }
    }

<<<<<<< HEAD
    cout << cnt << endl;

    return 0;
}

=======
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
>>>>>>> 0f1f0520a9794c3c2e08b76be2135dab47bc2194
