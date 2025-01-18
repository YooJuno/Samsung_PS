// https://www.acmicpc.net/problem/5597


#include <iostream>

using namespace std;

int main(){

    int* id = new int[31];
    for(int i=0 ; i<31 ; i++) id[i] = 0

    for(int i=0 ; i<28 ; i++){
        int num;
        cin>>num;
        id[num] = 1;
    }


    for(int i=1 ; i<31 ; i++){
        if(id[i] == 0) cout<<i<<endl;
    }

    return 0;
}