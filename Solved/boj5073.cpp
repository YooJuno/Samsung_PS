#include <iostream>

using namespace std;

// Equilateral :  세 변의 길이가 모두 같은 경우
// Isosceles : 두 변의 길이만 같은 경우
// Scalene : 세 변의 길이가 모두 다른 경우


int main(){

    string result[3] = {"Equilateral", "Isosceles", "Scalene"};

    int num1, num2, num3;
    cin >> num1 >> num2 >> num3;
    while(num1!=0 && num2!=0 && num3!=0){
        if((num1+num2<=num3) || (num1+num3<=num2) || (num2+num3<=num1))
            cout << "Invalid" << endl;
        else if(num1 == num2 && num2 == num3) 
            cout<<result[0]<<endl;
        else if((num1==num2 && num2!=num3) || (num2==num3 && num3!=num1) || (num1==num3 && num2!=num3))
            cout<<result[1]<<endl;
        else if(num1!=num2 && num2!=num3 && num3!=num1)
            cout<<result[2]<<endl;

        cin >> num1 >> num2 >> num3;
    }

    return 0;
}