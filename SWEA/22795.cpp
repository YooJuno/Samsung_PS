
/*'
https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&problemLevel=4&contestProbId=AZND_Dyq8SUDFAWB&categoryId=AZND_Dyq8SUDFAWB&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=1&problemLevel=3%2C4&&&&&&&&&
*/

#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;


    for(auto i=0 ; i<T ; i++){
        int heightes[6];
        auto sum = 0;
        auto max = 0;

        for (auto j=0 ; j<6 ; j++){
            cin >> heightes[j];
            sum += heightes[j];
            if(heightes[j] > max) max = heightes[j];
        }
        auto seven = max + 1;

        while((sum + seven)%7 != 0){
            ++seven;
        }
        cout << seven << endl;
    }

    return 0;
}