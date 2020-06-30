#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> power_permutation(int k, vector<int> seq){
    if(k==1) return seq;
    vector<int> seq2 = power_permutation(k/2, seq);

    vector<int> aux(seq2.size());
    for(int i = 0; i < seq2.size(); ++i) aux[i] = seq2[seq2[i]];

    if(k%2==1){
        vector<int> aux2 = aux;
        for(int i = 0; i < seq2.size(); ++i) aux2[i] = aux[seq[i]];
        aux = aux2;
    }

    return aux;
}

int main(){
    int n;
    while(cin >> n){
        vector<int> seq(n);
        for(int i = 0; i < n; ++i) cin >> seq[i];

        int k;
        cin >> k;
        vector<int> result;
        if(k==0){
            sort(seq.begin(), seq.end());
            result = seq;
        }
        else result = power_permutation(k, seq);

        for(int i = 0; i < n-1; ++i) cout << result[i] << ' ';
        cout << result[n-1] << endl;
    }
}
