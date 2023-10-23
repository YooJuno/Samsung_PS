#include <iostream>

using namespace std;

// 쿼터(Quarter, $0.25)의 개수
// 다임(Dime, $0.10)의 개수
// 니켈(Nickel, $0.05)의 개수
// 페니(Penny, $0.01)의 개수

// (1달러 = 100센트)

int main(){

    int T;
    cin >> T;

    int num;

    int cent[4] = {25, 10, 5, 1};

    for(int i=0 ; i<T ; i++){
        int cnt[4] = {0, 0, 0, 0};
        cin >> num;
        for(int j=0 ; j<4 ; j++){
            while(num-cent[j] >= 0){
                cnt[j]++;
                num -= cent[j];
            }
            if(num==0) break;
        }
        for(int j=0 ; j<4 ; j++) cout << cnt[j] << ' ';
        cout << endl;
    }

    return 0;
}