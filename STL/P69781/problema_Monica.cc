#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
	unordered_set<int> nums;
	pair<unordered_set<int>::iterator, bool> boss;
	int x, y, n, count;

	while (cin >> x >> y >> n){
		nums.clear();
		count = 0;

		boss = nums.insert(n);
		//cout << "nums.begin() = " << *nums.begin() << endl;
		//cout << "valor it = " << *(boss.first) << endl;
		//cout << "valor bool = " << boss.second << endl;
		//cout << "count = " << count << endl;
		//cout << "x = " << x << " y = " << y << " n = " << n << endl;
		//cout << endl;

		while(boss.second == true and n<= 100000000){
			if(n%2 == 0) n = n/2 + x;
			else n = 3*n + y;
			boss = nums.insert(n);

			for(auto it : nums) cout << it << ' ';
			cout << endl;
	                cout << "valor it = " << *(boss.first) << endl;
        	        cout << "valor bool = " << boss.second << endl;
	                cout << "n = " << n << endl << endl;
		}
	}
}
