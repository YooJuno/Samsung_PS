/*
////////// Do not remove //////////
코드 실행 : ctrl + opt(win) + N

*/

#include <iostream>
using namespace std;

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
