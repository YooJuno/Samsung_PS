// https://www.acmicpc.net/problem/15894

#include <iostream>

using namespace std;
/*
1 => 3 + 1
2 => arr[n-1] - (n-1) + n + 2 + 1   

*/
int main(){
    long long n;
    cin >> n;
    long long num1;
    long long num2=4;
    for(int i=0 ; i<n ; i++){
        num1 = num2;
        num2 = num1 - (i-1) + i + 3;
    }
    cout << num1 << endl;


    return 0;
}