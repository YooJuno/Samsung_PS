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

    cout << cnt << endl;

    return 0;
}

