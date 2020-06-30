#include <iostream>
#include <set>

using namespace std;

int main(){
	multiset<int> contenedor;
	string option;
	multiset<int>::iterator min;
	int max;
	double suma = 0;

	cout.setf(ios::fixed);
	cout.precision(4);

	while(cin >> option){
		if(option == "number"){
			int x; 
			cin >> x;
			suma += x;
			if(contenedor.size() == 0) max = x;
			if(max < x) max = x;
			contenedor.insert(x);
		}
		else{
			if(contenedor.size() > 0){
				suma -= *min;
				contenedor.erase(min);
			}
		}

		min = contenedor.begin();
		if(contenedor.size() == 0) cout << "no elements" << endl;
		else{
			cout << "minimum: " << *min << ", ";
			cout << "maximum: " << max << ", ";
			cout << "average: " << suma/contenedor.size() << endl;
		}
	}
}

