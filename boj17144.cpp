#include <iostream>

using namespace std;

int main(){

    int R, C, T;
    cin >> R >> C >> T; 
    int dust[51][51];
    int init[51][51];

    int air_top=-1, air_bot=-1;

    for(int i=0 ; i<R ; i++){
        for(int j=0 ; j<C ; j++){
            init[i][j] = 0;
            cin >> dust[i][j];
        
            // 공기청정기 위치
            if(dust[i][j]==-1 && air_top==-1){
                air_top = i;
                air_top = i+1;
            }
        }
    }

    

    return 0;
}