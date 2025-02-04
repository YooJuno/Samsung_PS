/*
////////// Do not remove //////////
코드 실행 : ctrl + opt(win) + N

*/

#include <iostream>
#include <set>

using namespace std;

struct Sketchbook 
{
    char image[3][3];
};

auto main() -> int
{
    set<char> abc;
    Sketchbook sketchbook;
    for(int i=0; i<3; i++)
    {
        cin >> sketchbook.image[i];
        for(int j=0; j<3; j++)
        {
            abc.insert(sketchbook.image[i][j]);
        }
    }

    for(auto ch : abc) cout << ch;


        
    
    return 0;
}

