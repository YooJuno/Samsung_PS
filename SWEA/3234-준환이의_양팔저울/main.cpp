#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int* weights;
int p[9] = {}

void scale(int arr[], int left, int right, int depth, int* cnt, int N, int sum)
{
    if(left < right)
    {
        return;
    }

    if(depth == N-1)
    {
        (*cnt)++;
        return;
    }

    if(left >= sum+right)
    {   
        int juno=1;
        int hi=0;
        for(int i=0; i<N; i++)
        {
            if(arr[i] != -1)
            {
                hi++;
                juno *= hi;
            }
        }
        (*cnt) += pow(2, hi)*juno;
        return;
    }

    for(int i=0; i<N ; i++)
    {   
        if(arr[i]==-1) continue;
        int temp = arr[i];
        arr[i] = -1;
        scale(arr, left + temp, right, depth + 1, cnt, N, sum-temp);
        scale(arr, left, right + temp, depth + 1, cnt, N, sum-temp); 
        arr[i] = temp;
    }
}

int main()
{
	freopen("sample_input.txt", "r", stdin);
	
    int T; cin>>T;
	
	for(int test_case = 1; test_case <= T; ++test_case)
	{
        int cnt = 0;
        int sum = 0;

        int N; cin >> N;
        // vector<int> v(N);
        
        int arr[N];

        for(int i=0; i<N; i++)
        {
            // cin >> v[i];
            // sum += v[i];
            cin >> arr[i];
            sum += arr[i];
        }

        for(int i=0; i<N; i++)
        {
            int temp = arr[i];
            arr[i] = -1;
            scale(arr, temp, 0, 0, &cnt, N, sum-temp);
            arr[i] = temp;
        }

        cout << '#' << test_case << ' ' << cnt << endl;

        delete weights;
	}

    return 0;
}