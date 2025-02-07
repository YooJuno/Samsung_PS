#include <vector>
#include <iostream>
using namespace std;

int prime(int num){
    bool c[3001];
    for(int i=2 ; i<=3000 ; i++) c[i] = true;
    c[1] = false;

    for(int i=2 ; (i*i)<=3000 ; i++){
        if(c[i] == true){
          for(int j=i+i ; j<=3000 ; j += i){
            c[j] = false;
          }
        }
    }
    if(c[num]) return 1;
    else return 0;
}
int solution(vector<int> nums) {
    int answer=0;
    
    // 포문 세 개를 이용하여 모든 경우의 수를 구해봄
    // 소수를 구하는 문제임으로 에라토스테네스의 체를 이용
    for(int i=0 ; i<nums.size()-2 ; i++){
        for(int j=i+1 ; j<nums.size()-1 ; j++){
            for(int k=j+1 ; k<nums.size() ; k++){
                int sum = nums[i] + nums[j] + nums[k];
                if(prime(sum)){
                    answer++;
                }
            }
        }
    }

    return answer;
}