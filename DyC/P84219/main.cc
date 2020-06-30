#include <iostream>
#include <vector>
using namespace std;


int first_occurrence(double x, const vector<double>& v)
{
	int inici = 0;
	int fi = v.size()-1;
	int mitja; 
	if(v.size() != 0 and (x > v[inici] or x < v[fi])) return -1;
	while(inici < fi){
		mitja = (inici +fi)/2;
		if(v[mitja] == x) fi = mitja;
		else{
			if(v[mitja] > x) inici = mitja+1;
			else fi = mitja-1;
		}
	}
	if(v[mitja] == x) return inici;
	return -1;
}


int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << first_occurrence(x, V) << endl;
        }
    }
}
