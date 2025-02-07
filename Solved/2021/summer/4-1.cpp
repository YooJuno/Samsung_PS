#include <iostream>


using namespace std;

int main() {
    int max = 0;
    int max_count;
    for(int i=0 ; i<5 ; i++){
        int sum=0;
        
        for(int j=0 ; j<4 ; j++){
            int num;
            cin>>num;
            sum += num;
        }
        if(sum>max){
            max=sum;
            max_count=i+1;
        } 
    }
    cout<<max_count<<' '<<max;
    
}