#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

typedef vector<vector<char>> matrix;

/*
void imprime_matriz(matrix m){
    for(int i = 0; i<m.size(); ++i){
        for(int j = 0; j<m[0].size(); ++j) cout << m[i][j] << ' ';
        cout << endl;
    }
}

void imprime_stack(stack<pair<int, int>> pos){
    pair<int, int> aux;
    while(pos.size()){
        aux = pos.top();
        pos.pop();
        cout << aux.first << ' ' << aux.second << endl;
    }
}
*/

bool accesible(matrix m, int i, int j){
    return (i>=0 and i<m.size() and
            j>=0 and j<m[0].size() and
            m[i][j] != 'X');
}


int dfs(matrix& m, stack<pair<int, int>> pos){
    int t = 0;
    while(not pos.empty()){
        int i = pos.top().first;
        int j = pos.top().second;
        pos.pop();

        if(m[i][j] == 't') ++t;
        m[i][j] = 'X';

        if(accesible(m, i+1, j)) pos.push(make_pair(i+1, j));
        if(accesible(m, i, j+1)) pos.push(make_pair(i, j+1));
        if(accesible(m, i-1, j)) pos.push(make_pair(i-1, j));
        if(accesible(m, i, j-1)) pos.push(make_pair(i, j-1));
    }
    return t;
}


int main(){
    int f, c;
    cin >> f >> c;

    matrix m(f, vector<char>(c));
    for(int i = 0; i < f; ++i){
        for(int j = 0; j < c; ++j) cin >> m[i][j];
    }

    int i, j;
    cin >> i >> j;
    i--;j--;

    stack<pair<int,int>> pos;
    if(m[i][j] != 'X') pos.push(make_pair(i, j));

    int t = dfs(m, pos);
    cout << t << endl;
}
