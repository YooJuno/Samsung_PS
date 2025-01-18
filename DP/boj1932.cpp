#include <iostream>

using namespace std;

int main(){

    int N;
    cin >> N;
    int** num = new int*[N];
    int** dp  = new int*[N];

    for(int i=0 ; i<N ; i++){
        num[i] = new int[i+1];
        dp[i]  = new int[i+1];
    }
    
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<=i ; j++){
            cin >> num[i][j];
        }
    }

    for(int i=N-1 ; i>0 ; i--){
        for(int j=0 ; j<i ; j++){
            num[i-1][j] += max(num[i][j], num[i][j+1]);

        }
    }
    cout<<num[0][0]<<endl;;

    return 0;
}
