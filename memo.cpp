#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void recursive(string& str, int idx, int& count) 
{
    if (idx == str.size()) 
    {
        if (str.find("BT") == string::npos && str.find("TB") == string::npos) 
        {
            count++;
        }
        return;
    }
    
    for (int i = idx; i < str.size(); i++) 
    {
        swap(str[idx], str[i]);
        recursive(str, idx + 1, count);
        swap(str[idx], str[i]);
    }
}

int main() 
{
    string str;
    cin >> str;
    
    int count = 0;
    recursive(str, 0, count);
    
    cout << count << endl;
    return 0;
}
