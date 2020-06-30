#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef map<int, int> Sequence;
typedef map<int, VI> Reverse;


int main(){
		int n, m;
		while(cin >> n >> m){
				Sequence s;
				Reverse r;
				//Leer
				for(int i=0; i<n; ++i){
						s[i] = 0;
						r = {};
				}
				for(int i=0; i<m; ++i){
						int previa, actual;
						cin >> previa >> actual;
						s[actual]++;
						r[previa].push_back(actual);
				}
				//Imprimimos tascas
				auto it = s.begin();
				while(s.size() and it != s.end()){
						if(it->second == 0){
								//Imprime valor
								cout << it->first;
								if(s.size() > 1) cout << ' ';
								//Borra preferencia
								for(int i : r[it->first]) s[i]--;
								//Borra valor
								s.erase(it);
								//Volvemos a empezar
								it = s.begin();
						}
						//Seguimos buscando
						else ++it;
				}
				cout << endl;
		}
}
