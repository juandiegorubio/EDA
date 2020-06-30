#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

typedef vector< vector<int> > Matrix;

//Lee el mapa
Matrix read_map(int row, int col){
	Matrix map(row, vector<int> (col) );
	char x;
	for(int i = 0; i < row; ++i){
		for(int j = 0; j < col; ++j){
			cin >> x;
			if(x == 'X') map[i][j] = -1;
			else if(x == 't') map[i][j] = 1;
			else map[i][j] = 0;
		}
	}
	return map;
}


//Busca si se puede llegar a algún tesoro
bool search_treasure(Matrix& map, int irow, int icol){

	//Pila que guarda las posiciones a visitar
	stack< pair<int, int> > pos;
	//Metemos la posición inicial en la pila
	if(irow >= 0 and icol >= 0 and irow < map.size() and icol < map[0].size()) pos.push(make_pair(irow, icol));

	//Miramos si en alguna posición encontramos el tesoro
	while(pos.size()){
		//Leemos y sacamos la posición top de la pila
		int i = pos.top().first;
		int j = pos.top().second;
		pos.pop();
		
		//Miramos que no entremos en una posición errónea
		if(map[i][j] != -1){
			//Miramos si la posición contiene el tesoro
			if(map[i][j]) return true;

			//Miramos las posiciones que podemos visitar desde nuestra posición
			else{
				if(i+1 < map.size() and map[i+1][j] != -1) pos.push(make_pair(i+1, j));
				if(j+1 < map[0].size() and map[i][j+1] != -1) pos.push(make_pair(i, j+1));
				if(i > 0 and map[i-1][j] != -1) pos.push(make_pair(i-1, j));
				if(j > 0 and map[i][j-1] != -1) pos.push(make_pair(i, j-1));
			}
		}
		//Marcamos la posición como visitada
		map[i][j] = -1;
	}
	return false;
}


//Función principal
int main(){

	//Lectura entradas
	int rows, col;
	cin >> rows >> col;
	Matrix map = read_map(rows, col);
	
	int irow, icol;
	cin >> irow >> icol;

	//Tratamos la entrada
	string result;
	if(search_treasure(map, irow-1, icol-1)) result = "yes";
	else result = "no";

	//Mostramos el resultado
	cout << result << endl;
}
