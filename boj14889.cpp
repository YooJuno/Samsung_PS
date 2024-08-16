#include <iostream>

using namespace std;

int main(){
    int N;

    cin >> N;
    int num[N][N];
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            cin >> num[i][j];
        }
    }

    int stat[N][N];
    bool flag[N];
    
    for(int i=0 ; i<N ; i++) flag[i] = false;

    for(int i=0 ; i<N ; i++){
        for(int j=i+1 ; j<N ; j++){
            stat[i][j] = num[i][j] + num[j][i];
            stat[j][i] = num[i][j] + num[j][i];
        }
    }

    return 0;   
}