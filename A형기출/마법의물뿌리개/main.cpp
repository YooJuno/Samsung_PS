#include <iostream>

using namespace std;

auto main() -> int
{
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
            if(maxHeight < heights[i]) maxHeight = heights[i];
            sumHeight += heights[i];
        }

        int remainingSum = maxHeight*N - sumHeight;
        
        // 뺴야 될 수를 3으로 산정해서 2, 1 이런 식으로 빼면 될듯
        // 2 부터 먼저 빼?
        // 마지막에 순서 안맞으면 어떡하지
        // 그니까 2를 빼면 무조건 1을 뺴고 가야됨
        // 2를 못빼면 1을 빼고 하면 될듯
        // 1만 남아있으면 무조건 1 먼저 빼는게 좋음
        // 2만 남아있으면 참고 2 빼는게 좋음
        // 총 합을 구해서 남아있는 값이 cntEven 값과 같을 때 까지 올려가야함.
        // 마지막에 값 이상해지면, 홀수로 빼주면 돼 

        int day = 0;
        int cntOdd = 0;
        int cntEven = 0;
        while(remainingSum > 0)
        {
            ++day;

            // 3 이상 남았을 때 => 1, 2 순서대로
            // 2 남았을 때 0, 2
            // 1 남았을 때 1, 0
            

            if(day%2 == 1)
            {
                
            }
            else
            {
                
            }
        }
        
        cout << '#' << test_case << ' ' << day+remainingSum << endl;
    }
    return 0;
}