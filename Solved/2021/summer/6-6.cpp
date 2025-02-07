#include <iostream>
#include <string>
#include <vector> 
using namespace std;

int main() {
    int N;
    cin>>N;
    vector <string> s;

    for(int i=0 ; i<N ; i++){
        string temp;
        cin>>temp;

        s.push_back(temp);
    }

    for(int i=0 ; i<N-1 ; i++){
        for(int j=i+1 ; j<N ; j++){
            // 첫 번째 조건
            if(s[i].size() > s[j].size()) s[i].swap(s[j]);

            else if(s[i].size() == s[j].size()){
                int sum_i=0;
                int sum_j=0;

                for(int k=0 ; k<s[i].size() ; k++)
                    if(48<=s[i][k]&&s[i][k]<=57) 
                        sum_i += s[i][k]-48; 
                for(int k=0 ; k<s[j].size() ; k++)
                    if(48<=s[j][k]&&s[j][k]<=57) 
                        sum_j += s[j][k]-48;

                // 두 번째 조건
                if(sum_i > sum_j) s[i].swap(s[j]);
                
                else if(sum_i == sum_j)
                    // 세 번째 조건
                    if(s[i].compare(s[j]) > 0) s[i].swap(s[j]);
            }
        }
    }

    for(int i=0 ; i<N ; i++) cout<<s[i]<<endl;
}

/*
A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인 것만 더한다)
만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.
*/