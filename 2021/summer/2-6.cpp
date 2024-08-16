#include <iostream>

using namespace std;

int main() {
    int num;
    cin>>num;
    int checker=0;

    for(int i=0 ; i<num ; i++){
        string str;
        cin>>str;

        int abc[26] = {0,};// 알파벳별로 몇 개씩 나왔는지

        //체크 가즈아
        for(int j=0 ; j<str.length() ; j++){
            abc[str[j]-97]++; // 해당 알파벳 갯 수 늘려

            //이미 이 전에 알파벳이 나왔고 연속되지 않을 때
            if(abc[str[j]-97]==2 && str[j]!=str[j-1]) 
                break; // 나가
            // 연속돼? 넌 봐줌
            else if(abc[str[j]-97]==2 && str[j]==str[j-1])
                abc[str[j]-97]--; // 다시 1로 돌아가
            
            if(j==str.length()-1) checker++;
        }
    }
    cout<<checker;
}