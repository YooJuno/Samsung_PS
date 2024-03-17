#include <iostream>

using namespace std;

int main(){

    int N;
    cin >> N;
    int num[N];
    int dp[N+1];
    int max_len=0;

    for(int i=0 ; i<N ; i++){
        dp[i]=1;
        cin >> num[i];

        for(int j=0 ; j<i ; j++){
            if(num[i]>num[j]) dp[i] = max(dp[j]+1, dp[i]);
        }
        if(dp[i] > max_len) max_len = dp[i];
    }
    cout << max_len << endl;


    return 0;   
}