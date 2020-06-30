#include <iostream>
using namespace std;

int power(int n, int k)
{
	if(k == 1) return n;
	else{
		int N = power(n, k/2);
		if(k%2 == 0) return N*N;
		else return N*N*n;
	}
}

int mod_exp(int n, int k, int m)
{
	if(k == 1) return n%m;
	else{
		int mod = mod_exp(n, k/2, m);
		return (k%2) ? (mod*mod)%m*n : (mod*mod)%m;
	}
}

int main(){
	int n, k, m;
	while(cin >> n >> k >> m) cout << mod_exp(n, k, m) << endl;
}
