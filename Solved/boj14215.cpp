#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int num[3];

    cin >> num[0] >> num[1] >> num[2];

    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<i ; j++){
            if(num[j]>num[i]){
                int temp = num[j];
                num[j] = num[i];
                num[i] = temp;
            }
        }
    }

    // cout << num[0] << num[1] << num[2] << endl;
    
    if((num[0]+num[1])<=num[2]) cout << (num[0]+num[1])+((num[0]+num[1])-1) << endl;
    else cout << (num[0]+num[1]) + num[2] << endl;

    return 0;
}