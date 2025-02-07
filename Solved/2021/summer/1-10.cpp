#include <iostream>

using namespace std;

int main() {
    int N;
    cin>>N;
    int participate = 0; // 5명 이상이 되는 알파벳이 있는지 확인용
    int alphabet[26] = {0,};// 각 알파벳별로 몇 명이 있는지 확인용
    char str[31];// 이름 입력을 위한 문자열

    for(int i=0 ; i<N ; i++){
        cin>>str;
        // 아스키코드를 이용하여 해당 알파벳에 수 추가
        alphabet[str[0]-97]++;
    }
    //사전순으로 출력하기 위해 새로운 포문을 만들어서 출력
    for(int i=0 ; i<26 ; i++){
        if(alphabet[i]>=5){
            participate = 1;
            char temp = i+97;
            cout<<temp;
        }   
    }
    // 5명 이상이되는 알파벳이 없다면
    if(participate==0) cout<<"PREDAJA";
}