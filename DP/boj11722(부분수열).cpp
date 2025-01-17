// https://www.acmicpc.net/problem/11722

// 문제
// 수열 A가 주어졌을 때, 가장 긴 감소하는 부분 수열을 구하는 프로그램을 작성하시오.

// 예를 들어, 수열 A = {10, 30, 10, 20, 20, 10} 인 경우에 가장 긴 감소하는 부분 수열은 A = {10, 30, 10, 20, 20, 10}  이고, 길이는 3이다.

// 입력
// 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

// 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

// 출력
// 첫째 줄에 수열 A의 가장 긴 감소하는 부분 수열의 길이를 출력한다.

// 예제 입력 1 
// 6
// 10 30 10 20 20 10
// 예제 출력 1 
// 3

#include <iostream>

using namespace std;

int main(){

    int N; // 1 <= N <= 1000
    int A[1001];
    int dp[1001]; // 배열 넘버까지의 최대 길이를 저장
    int longest=0;
    cin>>N;

    for(int i=0 ; i<N ; i++) cin>>A[i];
    
    for(int i=0 ; i<N ; i++){
        dp[i] = 1; // i를 기점으로 i보다 뒤에 있는 숫자들을 비교할거라서 초기 값은 1.
        for(int j=0 ; j<i ; j++){
            if(A[j] > A[i]){
                dp[i] = max(dp[i], dp[j]+1); 
                // 왜 여기서 dp[i]의 값을 신경써야 하지?
                // dp[i]의 값이 dp[j]+1 보다 큰 경우가 있나?
                // j=0부터 i까지 올라가면서 중간 중간에 증가되지 못한 j들이 있음
                // 근데 i는 j<i동안 계속 올라가니까 계속 추가될 수 있음
                // 즉 dp[i]가 dp[j]+1보다 큰 경우가 생김
            }
        }
        longest = max(longest, dp[i]);
        // cout<<"dp["<<i<<"] = "<<dp[i]<<endl;
    }

    // cout<<"longest : " << longest <<endl; 
    cout<< longest <<endl; 

    return 0;
}