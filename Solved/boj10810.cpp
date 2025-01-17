// https://www.acmicpc.net/problem/10810

#include <iostream>

using namespace std;

int main(){

    int N, M;
    cin >> N >> M;

    int* bucket = new int[N+1];
    for(int i=0 ; i<=N ; i++) bucket[i] = 0;
    

    

    for(int a=0 ; a<M ; a++){
        int i, j, k;
        cin >> i >> j >> k;

        for(int b=i ; b<=j ; b++){
            bucket[b] = k;
        }

    }
    for(int i=1 ; i<=N ; i++)
        cout << bucket[i] << ' ';
    cout << endl;
    return 0;
}