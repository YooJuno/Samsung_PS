#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin>>s;

    for(int i=0 ; i<s.length() ; i++){
        if(s[i]<=67) s[i] += 26; 
        s[i] -= 3;
        cout<<s[i];
    }
}