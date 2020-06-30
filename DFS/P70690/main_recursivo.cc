#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

typedef vector<vector<int>> Matrix;
typedef stack<pair<int, int>> Pila_pos;


//Lee el mapa por la entrada principal
Matrix leer_matriz(int row, int col){
	Matrix aux(row, vector<int>(col));
	char x;
	for(int i = 0; i < row; ++i){
		for(int j = 0; j < col; ++j){
			cin >> x;
			if(x == 'X') aux[i][j] = -1;
			else if(x == 't') aux[i][j] = 1;
			else aux[i][j] = 0;
		}
	}
}


bool on_range(int i, int j, Matrix ma){
	if(i >= 0 and j >= 0 and i < ma.size() and j < ma[0].size()) return true;
	return false;
}

bool search_treasure_rec(Matrix& ma, Pila_pos& pos){
	if(pos.empty()) return false;

	int i = pos.top().first;
	int j = pos.top().second;
	
	pos.pop();
	if(on_range(i, j, ma) and ma[i][j] != -1){
		if(ma[i][j]) return true;
		else{
			pos.push(make_pair(i+1, j));
			pos.push(make_pair(i, j+1));
			pos.push(make_pair(i-1, j));
			pos.push(make_pair(i, j-1));
		}
	}
	return search_treasure_rec(ma, pos);
}


//Función principal
int main(){
	int row, col;
	cin >> row >> col;
	Matrix ma = leer_matriz(row, col);
	int r, c;
	cin >> r >> c;
	r--; c--;

	Pila_pos pos;
	pos.push(make_pair(r, c));

	if(search_treasure_rec(ma, pos)) cout << "yes" << endl;
	else cout << "no" << endl;
}
