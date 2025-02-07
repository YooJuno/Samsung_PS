#include <iostream>
#include <string>

using namespace std;

int main() {
    string juno;
    int abc[26] = {0,};
    int max=0;
    int idx=-1;
    int flag=0;
    cin>>juno;
    // 대문자로 변환
    for(int i=0 ; i<juno.length() ; i++){
        if(juno[i]>=97) juno[i] -= 32;
        abc[juno[i]-65]++;
    }

    // 
    for(int i=0 ; i<26 ; i++){
        if(max<abc[i]){
            idx = i; 
            max = abc[i];
        }
    }
    for(int i=0 ; i<26 ; i++){
        if(i==idx) continue;
        if(abc[i]==max){
            cout<<'?';
            flag=1;
            break;
        }
    }
    if(flag==0){
        char temp = idx+65;
        cout<<temp;
    }
}