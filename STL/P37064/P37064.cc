#include <iostream>
#include <set>
using namespace std;

int main(){
	set<string> s;
	string word;
	cin >> word;
	set<string>::iterator it;
	
	while(word != "END"){
		s.insert(word);
		
		if(s.size() == 1) it = s.begin();

		else if(s.size()%2 == 0){
			if(*it > word) --it;
		}

		else{
			if(*it < word) ++it;
		}
		
		cout << *it << endl;
		cin >> word;
	}
}
