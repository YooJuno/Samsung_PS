// https://www.acmicpc.net/problem/9506

#include <iostream>
#include <vector>

using namespace std;

int main(){

    while(1){
        int num;
        cin >> num;
        if(num==-1) break;
        int sum=0;
        vector<int> v;

        for(int i=1 ; i<num ; i++){
            if(num%i==0){
                sum += i;
                v.push_back(i);
            }
        }
        if(sum == num){
            cout << num << " = ";
            for(int i=0 ; i<v.size() ; i++){
                if(i != 0) cout << " + ";
                cout << v[i];
            }
            cout << endl;
        }
        else cout << num << " is NOT perfect." << endl;

    }

    return 0;
}