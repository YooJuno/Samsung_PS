#include <iostream>
#include <string>

using namespace std;
enum{
    P = 10,
    S = 10
};
int main() {
    string s;
    cin>>s;

    int count = 0;
    int point [10] = {0,};
    int sum = 0;

    for(int i=0 ;i<10; i++){
        if(s[count]=='S'){
            point[i] += S;
            if(s[count+1]=='S') point[i] += 10;
            else if(s[count+1] != '-') point[i] += s[count+1]-48;

            if(s[count+2]=='S') point[i] += 10;
            else if(s[count+2] == 'P'){
                if(s[count+1]=='-') point[i] += 10;
                else point[i] += 10-(s[count+1]-48);
            }
            else if(s[count+2] != '-') point[i] += s[count+2]-48;
            
            count++;
        }
        
        // 숫자일 때
        else if(s[count] != '-'){
            point[i] = s[count++]-48;

            // 2번 째 기회에서 
            if(s[count] == 'P'){
                point[i] = 10;
                if(s[count+1]=='S') 
                    point[i] += 10;
                // 숫자일 때
                else if(s[count+1] != '-') 
                    point[i] += s[count+1]-48; // 스패어 안나옴
                
            }
            else if(s[count] != '-') point[i] += s[count]-48;
            count++;
        }
        else{
            count++;
            if(s[count] == 'P'){
                point[i] = 10;
                if(s[count+1]=='S') 
                    point[i] += 10;
                // 숫자일 때
                else if(s[count+1] != '-') 
                    point[i] += s[count+1]-48; // 스패어 안나옴
                
            }
            else if(s[count] != '-') point[i] += s[count]-48;
            count++;
        }
        
        sum += point[i];
    }
    cout<<sum;

}