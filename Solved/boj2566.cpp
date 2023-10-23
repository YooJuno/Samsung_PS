// https://www.acmicpc.net/problem/2566

#include <iostream>

using namespace std;


int main(){

    int num;
    int max_col, max_row;
    int max = -1;
    for(int i=1 ; i<=9 ; i++){
        for(int j=1 ; j<=9 ; j++){
            cin >> num;
            if(num > max){
                max_col = i;
                max_row = j;
                max = num;
            }
        }
    }

    cout << max << endl;
    cout << max_col << ' ' << max_row << endl;

    return 0;
}