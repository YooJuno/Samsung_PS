#include <iostream>
using namespace std;
int main() {
    int N;
    bool mode;
    cin>>N>>mode;
    if(N<=5){
        for(int i=2 ; i<=N ; i++){
            cout<<(i+mode+1)%2<<endl;
        }  
    }
    else cout<<"Love is open door";

}

/*
입력이 1이라면
처음   2* 는 0이고
    3*은 1이다.
    반대도 마찬가지


*/