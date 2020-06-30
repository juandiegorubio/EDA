#include <iostream>
#include <map>
using namespace std;

int main(){
	map<string, int> m;
	string player, action;

	while(cin >> player >> action){
		auto it = m.find(player);
		
		if(action == "enters"){
			if(it == m.end()) m.insert({player, 0});
			else cout << player << " is already in the casino" << endl;
		}
		
		else if(action == "leaves"){
			if(it != m.end()){ 
				cout << player << " has won " << it->second << endl;
				m.erase(it);
			}
			else cout << player << " is not in the casino" << endl;
		}
		
		else{
			int coins;
			cin >> coins;

			if(it == m.end()) cout << player << " is not in the casino" << endl;
			else it->second += coins;
		}
	}
	
	cout << "----------" << endl;
	for(auto it : m) cout << it.first << " is winning " << it.second << endl;
}
