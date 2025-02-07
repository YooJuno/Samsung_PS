#include <iostream>
#include <string>
using namespace std;
int main() {
    int num;
    cin>>num;
    for(int j=0 ; j<num ; j++){
        string OX;
        cin>>OX;
        int sum = 0;
        int temp = 0;
        
        for(int i=0 ; i<OX.length() ; i++){
            if(OX[i]=='O') sum += ++temp;
            else temp = 0;
        }
        
        cout<<sum<<endl;
    }
}