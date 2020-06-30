#include <iostream>
#include <vector>
using namespace std;

bool resistant_search_recursive(double x, const vector<double>& v, int l, int r){
    if(l+1>=r) return false;
    int m=(l+r)/2;
    if(v[m]==x or v[m-1]==x or v[m+1]==x) return true;
    if(v[m]>x) return resistant_search_recursive(x, v, l, m);
    return resistant_search_recursive(x, v, m, r);
}

bool resistant_search(double x, const vector<double>& v){
    if(!v.size()) return false;
    if(x!=v[0] and x!=v[v.size()-1]) return resistant_search_recursive(x, v, 0, v.size()-1);
    return true;
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
            cout << resistant_search(x, V) << endl;
        }
    }
}
