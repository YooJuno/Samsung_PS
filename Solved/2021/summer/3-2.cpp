#include <iostream>
using namespace std;


int main() {
    string s;
    cin>>s;

    for(int i=0 ; s[i]!='\0'; i++){
        cout<<s[i];
        if(i%10==9) cout<<endl;
    }

}