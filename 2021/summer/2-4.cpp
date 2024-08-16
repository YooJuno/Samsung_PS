#include <iostream>
#include <string>
using namespace std;

int number(char ch);

int main() {
    string dial;
    cin>>dial;
    int time=0;
    for(int i=0 ; i<dial.length() ; i++){
        time += number(dial[i]);
    }
    cout<<time;

}

int number(char ch){
    if     ('A'<=ch && ch<='C') return 3;
    else if('D'<=ch && ch<='F') return 4;
    else if('G'<=ch && ch<='I') return 5;
    else if('J'<=ch && ch<='L') return 6;
    else if('M'<=ch && ch<='O') return 7;
    else if('P'<=ch && ch<='S') return 8;
    else if('T'<=ch && ch<='V') return 9;
    else                        return 10;
}
/*
1 
2 A B C
3 D E F
4 G H I
5 J K L
6 M N O
7 P Q R S
8 T U V
9 W X Y Z
*/