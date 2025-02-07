#include <iostream>

using namespace std;

int main() {
    int N;
    cin>>N;
    bool num[2001] = {false,};
    for(int i=0 ; i<N ; i++){
        int temp;
        cin>>temp;
        temp += 1000;
        num[temp] = true;
    }   
    for(int i=0 ; i<=2000 ; i++)
        if(num[i]==true) cout<<i-1000<<' ';
    
}