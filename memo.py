#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d;
  
  	cin >> a >> b >> c >> d;
  
  	int average = (a+b+c+d)/4;
  
  	if(a < average) cout << a << "<" << average;
  	else if (a == average) cout << a << "==" << average;
  	else if (a > average) cout << a << ">" << average;
  	
  	cout << endl;
  
  	if(b < average) cout << b << "<" << average;
  	else if (b == average) cout << b << "==" << average;
  	else if (b > average) cout << b << ">" << average;
  	
  	cout << endl;
  
  	if(c < average) cout << c << "<" << average;
  	else if (c == average) cout << c << "==" << average;
  	else if (c > average) cout << c << ">" << average;
  	
  	cout << endl;
  
  	if(d < average) cout << d << "<" << average;
  	else if (d == average) cout << d << "==" << average;
  	else if (d > average) cout << d << ">" << average;

	return 0;
}