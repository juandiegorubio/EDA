#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int fixed_point(int x, const vector<int>& v, int l, int r){
    if(l>r) return -1;
    int m=(l+r)/2;
    int suma=v[m]+x;
    if(suma==m+1){
        int minimum = fixed_point(x, v, l, m-1);
        if(minimum != -1) return minimum;
        return m;
    }
    if(suma>m+1) return fixed_point(x, v, l, m-1);
    return fixed_point(x, v, m+1, r);
}

int main(){
    int n;
    int count = 1;
    while(cin >> n){
        vector<int> v(n);
        for(int i = 0; i < n; ++i) cin >> v[i];

        int m;
        cin >> m;
        cout << "Sequence #" << count++ << endl;
        for(int i = 0; i < m; ++i){
            int x;
            cin >> x;

            int result = fixed_point(x, v, 0, v.size()-1);
            if(result != -1) cout << "fixed point for " << x << ": " << result+1 << endl;
            else cout << "no fixed point for " << x << endl;

        }
        cout << endl;
    }
}
