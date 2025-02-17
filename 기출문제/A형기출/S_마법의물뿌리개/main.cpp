#include <iostream>
#include <algorithm>
using namespace std;

auto main() -> int
{
    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    for(auto test_case=1; test_case<=T; test_case++)
    {
        int N; cin >> N;
        
        int heights[N];
        int maxHeight = 0;
        int sumHeight = 0;
        for(auto i = 0; i < N; i++)
        {
            cin >> heights[i];
            if(maxHeight < heights[i]) 
            {
                maxHeight = heights[i];
            }
            sumHeight += heights[i];
        }
        sort(heights, heights+N, greater<int>());

        int remainingSum = maxHeight*N - sumHeight;

        int day = 0;
        int cntOdd = 0;
        int cntEven = 0;

        while(remainingSum > 0)
        {
            ++day;

            for(auto i = 0; i < N; i++)
            {   
                int remaingHeight = maxHeight - heights[i];
                if(remaingHeight == 0)
                {
                    continue;
                }
                else if(remaingHeight == 1)
                {
                    if(day%2==1)
                    {
                        heights[i] += 1;
                        remainingSum -= 1;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
                else if(remaingHeight == 2)
                {
                    if(day%2==0)
                    {
                        heights[i] += 2;
                        remainingSum -= 2;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                    
                }
                else if(remaingHeight > 2)
                {
                    if(day%2==0)
                    {
                        heights[i] += 2;
                        remainingSum -= 2;
                        break;
                    }
                    else
                    {
                        heights[i] += 1;
                        remainingSum -= 1;
                        break;
                    }
                }
            }
        }
        
        cout << '#' << test_case << ' ' << day << endl;
    }
    return 0;
}