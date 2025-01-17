// https://www.acmicpc.net/problem/14501

/*

[생각정리]
- 회의실 배정 문제에 가중치를 더한 문제 같음.
- dp를 써야 하는데 감이 안잡힘.
- knapsack problem과 비슷하게 풀어야 할까?
- DP변수를 이용해서 그 날까지의 이익을 저장하는 변수를 두자

*/

#include <iostream>

using namespace std;

int main(){

    int N;
    cin>>N;

    int dp[15+2];

    int T[15+2];
    int P[15+2];

    for(int i=1 ; i<=N ; i++) cin>>T[i]>>P[i];

    for(int i=N ; i>=1 ; i--){
        dp[i]=0;
        
        if(i+T[i]<=N){
            dp[i+T[i]] = max(dp[i+T[i]], dp[i]+P[i]);
        }
        
    }

    return 0;
}