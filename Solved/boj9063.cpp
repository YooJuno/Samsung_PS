#include <iostream>


using namespace std;


int main(){

    int N;
    cin >> N;
    int x,y;
    cin >> x >> y;
    int max_x=x, max_y=y, min_x=x, min_y=y;

    for(int i=0 ; i<N-1; i++){
        cin >> x >> y;

        if(x>max_x) max_x = x;
        else if(x<min_x) min_x=x;

        if(y>max_y) max_y=y;
        else if(y<min_y) min_y=y;
    }

    cout << (max_x-min_x)*(max_y-min_y) << endl;

    return 0;
}