// https://www.acmicpc.net/problem/10811

#include <iostream>
#define swap(x,y) {int temp = x; x = y ; y = temp;}

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    int* bucket = new int[N+1];
    for(int i=0 ; i<=N ; i++) bucket[i] = i;

    for(int cnt=0 ; cnt<M ; cnt++){
        int i,j;
        cin >> i >> j;
        for(int idx=0 ; idx<=(j-i)/2 ; idx++){
            swap(bucket[i+idx], bucket[j-idx]);
        }
    }

    for(int i=1 ; i<=N ; i++) cout << bucket[i] << ' ';
    cout << endl;
    

    return 0;
}