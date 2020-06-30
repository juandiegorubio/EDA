#include <iostream>

using namespace std;

int exponente(int base, int exp){
	if(exp == 1) return base;
	else{
		int x = exponente(base, exp/2);
		if(exp%2) return x*x*base;
		else return x*x;
	}
}

int main()
{
	int base, exp;
	while(cin >> base >> exp) cout << exponente(base, exp) << endl;
}
