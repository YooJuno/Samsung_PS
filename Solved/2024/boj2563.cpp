// https://www.acmicpc.net/problem/2563

#include <iostream>


using namespace std;


int main(){

    int n;
    cin>>n;

    int dx[n];
    int dy[n];

    bool paper[101][101] = {false, };


    for(int i=0 ; i<n ; i++){
        cin >> dx[i] >> dy[i];
        for(int j=dy[i]; j<dy[i]+10 ; j++){
            for(int k=dx[i] ; k<dx[i]+10 ; k++){
                paper[j][k] = true;
            }
        }
    }
    int sum=0;
    for(int i=1 ; i<=100 ; i++){
        for(int j=1 ; j<=100 ; j++){
            if(paper[i][j]==true) sum++;
        }
    }
    cout << sum << endl;


    return 0;
}