#include <iostream>
using namespace std;
int main() {
    int num;
    cin>>num;

    for(int i=0 ; i<num ;i++){
        string name;
        cin>>name;
        for(int j=0 ; j<name.length() ; j++) {
            if(name[j]=='Z') name[j] = 'A';
            else name[j]++;
        }
        cout<<"String #"<<i+1<<endl<<name<<endl<<endl;
    }
}