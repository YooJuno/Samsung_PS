// https://www.acmicpc.net/problem/2745

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// A  ~ Z
// 65 ~ 90

int main(){
    long long sum = 0;

    string N;
    int B;
    cin >> N >> B;
    int num;
    // cout << N ;
    for(int i = 0 ; i<N.length() ; i++){
        if( 65<=N[i] && N[i]<=90 ){
            num = N[i]-55;
        }
        else if( 48<=N[i] && N[i]<=57 ){
            num = N[i]-48;
        }

        sum += num * pow(B,N.length()-1-i);
    }
    cout << sum << endl;

    return 0;
}