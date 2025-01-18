#include <iostream>

using namespace std;
// 'A' == 65
int main()
{	
  	int num; cin >> num;
  
	int arr[4][4];
  	
  	for(int i=0 ; i<16 ; i++)
    {
      	arr[i/4][i%4] = num+i; 
        cout << arr[i/4][i%4];
      	(i%4==3) ? cout << " \n" : cout<< " ";
    }
  
	return 0;
}