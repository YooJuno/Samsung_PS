#include <iostream>

using namespace std;

int table[16][16];
int arr[8];
int minV;

void recursive(int depth, int idx, int N, int totalSum, int halfSum)
{
    
    if(depth == N/2-1)
    {
        for(auto e : arr)
        {
            cout << e << ' ';
        }
        cout << " => " << abs(totalSum - halfSum*2) <<  endl;
        if(minV > abs(totalSum - halfSum*2)) 
        {
            minV = abs(totalSum - halfSum*2);
            cout << " => " << minV << endl;
        }
        return;
    }
    
    for(auto i = 0; i < depth; i++)
    {
        halfSum += table[arr[i]][arr[depth]];   
    }

    for(auto i = idx; i < N; i++)
    {
        arr[depth+1] = i;
        recursive(depth+1, i+1, N, totalSum, halfSum);
        arr[depth+1] = -1;
    }
}

auto main() -> int
{
    freopen("sample_input.txt", "r", stdin);

    int T; cin >> T;
    // for(auto test_case=1; test_case<=T; test_case++)
    for(auto test_case=1; test_case<=2; test_case++)
    {
        memset(table, 0, sizeof(table));
        memset(arr, -1, sizeof(arr));
        minV = 20000 * 16 * 16 + 1;

        int result = 0;
        int totalSum = 0;
        int N; cin >> N;

        for(auto i = 0; i < N; i++)
        {
            for(auto j = 0; j < N; j++)
            {
                cin >> table[i][j];
                totalSum += table[i][j];
                if(i>j) table[j][i] += table[i][j];
            }
        }

        for(auto i = 0; i < N/2; i++)
        {
            arr[0] = i;
            recursive(0, i+1, N, totalSum, 0);
            arr[0] = -1;
        }
        
        cout << '#' << test_case << ' ' << minV << endl;
    }
    return 0;
}