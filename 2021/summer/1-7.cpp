#include <iostream>

using namespace std;


int main() {
    int type[5] = {0,};
    int N; // 창문 갯 수
    int M; // 층 수
    cin>>M>>N; // 입력

    // 아파트 그림을 위한 2차원 배열
    char apt[5*M+1][5*N+1];
    // 입력받을 때 밑에서부터 입력받는 것이 아닌 위에서부터 입력하는 것으로 하였음
    // 이유는 왼쪽 밑이 [0][0]으로 만들고싶었기 때문
    for(int i=M*5 ; i>=0 ; i--){
        for(int j=0 ; j<N*5+1 ; j++){
            cin>>apt[i][j];
        }
    }

    // 층 올라가~
    for(int i=0 ; i<M ; i++){
        // 옆집으로 가~
        for(int j=0 ; j<N ; j++){
            //블라인드 올라가~
            for(int k=0 ; k<=4 ; k++){
                // 별이 하나도 없으면
                if(k==4){
                    type[0]++;
                    break;
                }
                // 별이 하나씩이라도 있다면
                else if(apt[5*i+1+k][j*5+1]=='*'){
                    type[4-k]++;
                    break;
                }
            }
        }
    }

    for(int i=0 ; i<5 ; i++) cout<<type[i]<<' ';
}   