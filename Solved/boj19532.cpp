// https://www.acmicpc.net/problem/19532


#include <iostream>

using namespace std;

int main(){

    int a,b,c,d,e,f;

    cin >> a >> b >> c >> d >> e >> f;

    // a*x + b*y == c
        // x = c/a - (b/a)*y
    // d*x + e*y == f
        // x = f/d - (e/d)*y
    
    // 0 = c/a - f/d +(e/d - b/a)y

    float y = (f*a - c*d)/(e*a - b*d);
    float x = (f*b - c*e)/(d*b - a*e);

    cout << (int)x << ' ' << (int)y << endl;

    return 0;
}