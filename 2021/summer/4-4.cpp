#include <iostream>
using namespace std;


int main() {
    int n;
    cin>>n;

    for(int i=0 ; i<n ; i++){
        int height , width;
        cin>>height>>width;
        int num[height+1][width];
        
        for(int j=0 ; j<=height ; j++){
            if(j==0){
                for(int k=0 ; k<width ; k++){
                    num[j][k] = k+1;
                }
            }
            else{
                int sum=0;
                for(int k=0 ; k<width ; k++){
                    sum += num[j-1][k];
                    num[j][k] = sum;
                }
            }
        }
        cout<<num[height][width-1]<<endl;

    }
    
}