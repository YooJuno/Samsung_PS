#include <iostream>
#include <algorithm>

using namespace std;

bool bisearch(int idx_low, int idx_mid, int idx_high, int target_num, int* num1){
    while(idx_low <= idx_high){
        if(target_num == num1[idx_mid]){
            return true;
        }
        else if(num1[idx_mid] < target_num){
            idx_low = idx_mid+1;
        } 
        else{
            idx_high = idx_mid-1;
        }
        idx_mid = (idx_high + idx_low)/2;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;
    int num1[N];

    for(int i=0 ; i<N ; i++){
        cin >> num1[i];
    }

    sort(num1, &num1[N]);

    int M;
    cin >> M;
    int target_num;

    int idx_low, idx_mid, idx_high;
    idx_low=0 ; 
    idx_high = N-1 ; 
    idx_mid = (idx_low + idx_high)/2;
    for(int i=0 ; i<M ; i++){
        cin>>target_num;

        cout << bisearch(idx_low, idx_mid, idx_high, target_num, num1) << "\n";

    }

    return 0;
}

