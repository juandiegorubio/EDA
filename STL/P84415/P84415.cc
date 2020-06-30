#include <iostream>
#include <map>
using namespace std;

int main(){
        map<string, int> m;
        string action;
        while(cin >> action){
                if(action == "minimum?"){
                        if(m.empty()) cout << "indefinite minimum" << endl;
                        else cout << "minimum: " << m.begin()->first << ", " << m.begin()->second << " time(s)" << endl;
                }

                else if(action == "maximum?"){
                        if(m.empty()) cout << "indefinite maximum" << endl;
                        else cout << "maximum: " << (--m.end())->first << ", " << (--m.end())->second << " time(s)" << endl;
                }

                else{
                        string n;
                        cin >> n;
                        
			if(action == "store") m[n]++;
                        else{
                                auto it = m.find(n);
                                if(it != m.end()){ 
					if(it->second == 1) m.erase(it);
					else it->second -= 1;
				}
                	}
		}
        }
}

