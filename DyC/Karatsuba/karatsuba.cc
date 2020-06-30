#include <iostream>
#include <math.h>
using namespace std;

int tamano(int x)
{	
	int i = 0;
	for( ; x > 0; ++i) x/=10;
	return i;
}

int karatsuba(int x, int y)
{
	int size = tamano(x);
	if(size == 1) return x*y;
	
	else{
		int base = pow(10, size/2);

		int Xe = x/base;
		int Xd = x%base;
	
		int Ye = y/base;
		int Yd = y%base;

		int a = karatsuba(Xe, Ye);
		int b = karatsuba(Xd, Yd);
		int c = karatsuba(Xe+Xd, Ye+Yd);

		return pow(base, 2)*a + base*(c-a-b) + b;
	}
}

int main(){
	int x, y;
	while(cin >> x >> y) cout << karatsuba(x, y) << endl;
}
