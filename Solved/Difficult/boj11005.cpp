// https://www.acmicpc.net/problem/11005

#include <iostream>
#include <algorithm>

using namespace std;

/*
[생각 정리]
1 씩 차감해 가면서 B를 넘어가면 다음 배열러 carry를 보내면 될거 같음.
근데 이렇게 하면 오래 걸릴거 같아서
*/

char result[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
                    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 
                    'U', 'V', 'W', 'X', 'Y', 'Z'};
// 60466175 36

int main(){
    
    int max_cnt=0;
    long long N , B;
    cin >> N >> B;
    int trans[1000] = {0,};

    while(N-B>=0){
        long long temp_B = B;
        for(int i=1 ; i<1000 ; i++){
            // 10 100
            if(temp_B*B <= N){
                // cout<<"if [i="<<i<<"] " << "[temp_B="<<temp_B<<"]" <<endl;
                temp_B = temp_B*B;
            }
            else{
                if(max_cnt < i) max_cnt = i;
                // cout<<"else [i="<<i<<"] "<< "[temp_B="<<temp_B<<"]"<<endl;
                while(N-temp_B>=0){
                    trans[i] += 1;
                    N -= temp_B;
                }
                break;
            }
        }
        // cout << endl;
    }
    trans[0] = N;

    for(int i=max_cnt ; i>=0 ; i--) cout << result[trans[i]];
    cout << endl;
    return 0;
}