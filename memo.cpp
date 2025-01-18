<<<<<<< HEAD
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
=======
#include <iostream>

using namespace std;

enum Test{
	a,
	b,
	c,
	d
};

Test t = a;

int main()
{	
	
  	cout << t << endl;
    return 0;
>>>>>>> 9d73eec317374ac12fc6df377b91620f371fe3ac
}