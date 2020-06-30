#include <iostream>
#include <vector>
using namespace std;

int inversions(const vector<int>& v, int l, int r){
    if(l<=r){
        int m = (l+r)/2;
        int aux = 0;
        if(m>0 and v[m-1]>v[m]) aux++;
        if(m+1<=v.size()-1 and v[m]>v[m+1]) aux++;
        return aux+inversions(v, l, m-1)+inversions(v, m+1, r);
    }
    return 0;
}

int main(){
    int n;
    while(cin >> n){
        vector<int> v(n);
        for(int i = 0; i < n; ++i) cin >> v[i];
        cout << inversions(v, 0, v.size()-1) << endl;
    }
}
