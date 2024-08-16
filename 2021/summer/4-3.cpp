#include <iostream>
using namespace std;
int main() {
    bool juno[42] = {0,};
    int cnt = 0;
    for(int i=0 ; i<10 ; i++){
        int num;
        cin>>num;

        num %= 42;
        
        if(juno[num]==false)cnt++;
        juno[num] = true;
    }
    cout<<cnt;
}