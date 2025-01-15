#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;

    for(auto test_case=0 ; test_case<T ; test_case++){
        int L, R;
        cin >> L >> R;

        auto arr = new int[R-L+1];

        for(int i=0 ; i<R-L+1 ; i++) arr[i] = L+i;
        
    }

    return 0;
}