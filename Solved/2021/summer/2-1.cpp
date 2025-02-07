#include <iostream>
#include <string>

using namespace std;
int main() {
    
    string pw;

    while(getline(cin,pw)){
        if(!pw.compare("end")) break; // 탈출조건

        int count_moeum=0; // 모음 세 개 이상 연속으로 들어오르 때
        int count_jaeum=0; // 자음 세 개 이상 연속으로 들어오르 때
        bool accept = true; // 디폴트로 가능으로 두고 조건에 맞지 않으면 false로 바꿈
        bool moeum = false; // 모음이 하나라도 나오면 true.
        // 두 개의 bool은 디폴트 값이 다른 이유는 accept는 맞지 않는 조건을 찾는 것이고
        // moeum은 맞는 조건을 찾는 것이기 때문에 다름

        for(int i=0 ; i<pw.length() ; i++){
            // 모음
            if(pw[i]=='a' || pw[i]=='e' || pw[i]=='i' || pw[i]=='o' || pw[i]=='u'){
                moeum = true;
                count_jaeum = 0; // 자음 카운트 초기화
                count_moeum++;   // 모음 카운트

                // 같은 글자가 두 개 들어오는 중 그 글자가 e, o가 아니면 불가능으로
                // 또한 모음이 연속으로 3개 연속으로 들어오면 불가능으로
                if((i>0 && pw[i]==pw[i-1] && !(pw[i]=='e' || pw[i]=='o')) || count_moeum == 3){
                    accept = false;
                    break;
                }
            }
            //자음
            else{
                count_jaeum++;    // 자음 카운트
                count_moeum = 0; // 모음 카운트 초기화

                // 자음은 e, o 상관 없이 무조건 2개 연속 같은 글자면 짤
                if(count_jaeum == 3 || (i>0 && pw[i]==pw[i-1])){
                    accept = false;
                    break;
                }
            }
        }
        if(accept == true && moeum == true) cout<<'<'<<pw<<"> is acceptable."<<endl;
        else cout<<'<'<<pw<<"> is not acceptable."<<endl;
    }
}
/*
모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.*/