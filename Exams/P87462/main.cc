#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

typedef vector<vector<int>> Matrix;

void imprime(Matrix map, queue<pair<int, int>> pos){
	for(int i = 0; i < map.size(); ++i){
		for(int j = 0; j < map[0].size(); ++j){
			if(map[i][j] != -1) cout << ' ';
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}

	queue<pair<int, int>> aux = pos;
	while(aux.size()){
		cout << '(' << aux.front().first << ',' << aux.front().second << ')' << ' ';
		aux.pop();
	}
	cout << endl;
}

//Busca si encuentra una B
bool menja_bfs(Matrix& map, queue<pair<int, int>>& pos){
	if(pos.size()){
		int r = pos.front().first;
		int c = pos.front().second;
		imprime(map, pos);
		pos.pop();
		
		if(map[r][c] == 1) return true;
		
		map[r][c] = -1;
		if(map[r+1][c] != -1) pos.push(make_pair(r+1, c));
		if(map[r][c+1] != -1) pos.push(make_pair(r, c+1));
		if(map[r-1][c] != -1) pos.push(make_pair(r-1, c));
		if(map[r][c-1] != -1) pos.push(make_pair(r, c-1));
		if(map[r+1][c+1] != -1) pos.push(make_pair(r+1, c+1));
		if(map[r+1][c-1] != -1) pos.push(make_pair(r+1, c-1));
		if(map[r-1][c+1] != -1) pos.push(make_pair(r-1, c+1));
		if(map[r-1][c-1] != -1) pos.push(make_pair(r-1, c-1));
		
		return menja_bfs(map, pos);
	}
	return false;
}

//Lee entrada
pair<int, int> read_map(Matrix& map, int rows, int cols){
	char x;
	pair<int, int> inicial;
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < cols; ++j){
			cin >> x;
			if(x == 'P') inicial = make_pair(i, j);
			else if(x == 'B') map[i][j] = 1;
			else if(x == 'F' or x == 'X') map[i][j] = -1;
			else map[i][j] = 0;
		}
	}
	return inicial;
}

//Función principal
int main(){
	int rows, cols;
	while(cin >> rows >> cols){
		Matrix map(rows, vector<int>(cols));
		pair<int, int> pos_inicial = read_map(map, rows, cols);
		
		queue<pair<int, int>> pos;
		pos.push(pos_inicial);
		if(menja_bfs(map, pos)) cout << "yes" << endl;
		else cout << "no" << endl;
		cout << endl;
  	}
}
