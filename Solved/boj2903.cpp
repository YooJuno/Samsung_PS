// https://www.acmicpc.net/problem/2903

#include <iostream>

using namespace std;

int main(){

    int N;
    cin >> N;

    int num = 2;

    for(int i=0 ; i<N ; i++){
        num = num*2 - 1;
    }
    cout << num*num << endl;

    return 0;  
}