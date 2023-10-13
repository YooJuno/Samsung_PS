// https://www.acmicpc.net/problem/14501


/*
[생각정리]
회의실 배정 문제에 가중치를 더한 문제 같음.
dp를 써야 하는데 감이 안잡힘.
knapsack problem과 비슷하게 풀어야 할까?
*/


#include <iostream>

using namespace std;


int main(){

    int N;
    cin>>N;

    int* T = new int[N];
    int* P = new int[N];
    float* V = new float[N];
    

    for(int i=0 ; i<N ; i++){
        cin >> T[i] >> P[i];
        // V[i] = P[i]/T[i];
    }

    for(int i=0 ; i<N ; i++){

    }




    return 0;
}