// https://www.acmicpc.net/problem/10813

#include <iostream>

#define swap(x,y) {int temp = x; x = y ; y = temp; }

using namespace std;

int main(){
    int N, M;

    cin >> N >> M;

    
    
    int* bucket = new int[N+1];
    for(int i=0 ; i<=N ; i++) bucket[i] = i;

    for(int a=0 ; a<M ; a++){
        int i, j;
        cin >> i >> j;

        swap(bucket[i], bucket[j]);
    }

    for(int i=1 ; i<=N ; i++) cout << bucket[i] << ' ';
    cout<<endl;

    return 0;
}