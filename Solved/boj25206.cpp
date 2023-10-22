// https://www.acmicpc.net/problem/25206

#include <iostream>
#include <string>

using namespace std;

int main(){

    string name;
    double credits;
    double credits_sum=0;
    double sum=0;
    string grade;

    for(int i=0 ; i<20 ; i++){
        cin >> name >> credits >> grade;


        if( grade == "A+") sum += credits * 4.5;
        else if( grade == "A0") sum += credits * 4.0;
        else if( grade == "B+") sum += credits * 3.5;
        else if( grade == "B0") sum += credits * 3.0;
        else if( grade == "C+") sum += credits * 2.5;
        else if( grade == "C0") sum += credits * 2.0;
        else if( grade == "D+") sum += credits * 1.5;
        else if( grade == "D0") sum += credits * 1.0;
        else if( grade == "F") sum += credits * 0.0;

        if(grade != "P") credits_sum += credits;
        
    }
    cout.precision(7);
    cout << sum/credits_sum << endl;

    return 0;
}