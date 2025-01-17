// https://www.acmicpc.net/problem/10798
#include <iostream>
#include <string>

using namespace std;

int main(){
    string str[5];
    
    for(int i=0 ; i<5 ; i++) cin >> str[i];

    for(int i=0 ; i<15 ; i++){
        for(int j=0 ; j<5 ; j++){
            if(str[j].length() <= i) continue;
            cout << str[j][i];
        }
    }
    cout << endl;
        
    return 0;
}