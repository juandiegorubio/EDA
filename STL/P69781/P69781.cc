#include <iostream>
#include <vector>
using namespace std;

int main(){
	int x, y, n;
	while(cin >> x >> y >> n){

		bool found = false;
		int i;
		vector<int> v;
		while(not found and n <= 100000000){ 
			v.push_back(n);

			if(n%2 == 0) n = (n/2 + x);
			else n = (3*n + y);
			
			i = 0;
			while(not found and i != v.size()){
				found = (v[i] == n);
				++i;
			}
		}

		if(found) cout << v.size() - (i-1) << endl;
		else cout << n << endl;
	}
}
