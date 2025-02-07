#include <iostream>
using namespace std;

int main() {
    // 입력받을 8개의수를 위한 배열 생성
    int num[8];

    // 첫 번째 숫자를 확인하여 1이아니고 8이 아니면 바로 mixed 출력
    cin>>num[0];
    if(num[0]!=1 && num[0]!=8) cout<<"mixed"<<endl;

    // 그 외의 숫자들을 확인
    else{
        int flag = 0; //mixed판정 시 1 할당 

        // ascending을 위한 조건문
        if(num[0]==1){

            for(int i=1 ; i<8 ; i++){
                cin>>num[i];
                // 어센딩 조건 어길 시
                if(num[i]-num[i-1]!=1){
                    // 플래그에 1 넣고 바로 for문 탈출
                    flag = 1;
                    break;
                } 
            }
            if(flag==1) cout<<"mixed"<<endl;
            else cout<<"ascending"<<endl;
        }
        // 위의 조건문에서 1을 -1로 바꿔줌
        else{
            for(int i=1 ; i<8 ; i++){
                cin>>num[i];
                if(num[i]-num[i-1]!=-1){
                    flag = 1;
                    break;
                } 
            }
            if(flag==1) cout<<"mixed"<<endl;
            else cout<<"descending"<<endl;
        }
    }
}