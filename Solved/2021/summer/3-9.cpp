#include <iostream>
#include <vector>
#include <string>
using namespace std;



int main() {
    vector <string> v;

    int n;
    cin>>n;

    int count = n%14;
    int times = n/14;
    if(count == 1) cout<<"baby";
    else if(count == 2) cout<<"sukhwan";
    else if(count == 5) cout<<"very";
    else if(count == 6) cout<<"cute";
    else if(count == 9) cout<<"in";
    else if(count == 10) cout<<"bed";
    else if(count == 13) cout<<"baby";
    else if(count == 0) cout<<"sukhwan";
    else{
        if(count==3 || count==7 || count==11){
            if(times>=3) {
                cout<<"tu+ru*"<<times+2;
            }
            else{
                string s = "tururu";
                for(int i=0 ; i<times ; i++) s += "ru";
                cout<<s;
            }
        }
        else{
            if(times>=4) cout<<"tu+ru*"<<times+1;
            else{
                string s = "turu";
                for(int i=0 ; i<times ; i++) s += "ru";
                cout<<s;
            }
        } 
        
    }
}