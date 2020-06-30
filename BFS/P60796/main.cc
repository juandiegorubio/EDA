#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

typedef vector<vector<int>> Matrix;
typedef queue<pair<int, int>> Position;
	
/* Funciones añadidas para comprovar:
 * imprime(Matrix ma, Position pos);
 */

void imprime(Matrix ma, Position pos){
	//Imprime matriz
	for(int i = 0; i < ma.size(); ++i){
		for(int j = 0; j < ma[0].size(); ++j){
			if(ma[i][j] > -1 and ma[i][j] < 10) cout << ' ' << ma[i][j] << ' ';
			else cout << ma[i][j] << ' ';
		}
		cout << endl;
	}

	Position aux = pos;
	while(aux.size()){
		cout << '(' << aux.front().first << ',' << aux.front().second << ')' << ' ';
		aux.pop();
	}
	cout << endl;
}

//Devuelve si la posición ma[r][c] existe en la matriz
bool on_range(Matrix ma, int r, int c){
	return r >= 0 and c >= 0 and r < ma.size() and c < ma[0].size();
}

//Calcula la distancia mínima a un tesoro o -1 si no llega a ninguno
int bfs(Matrix& ma, Position& pos){
	//Miramos si no hay más posiciones que visitar
	if(pos.empty()) return -1;
	else{
		//Cogemos el primer valor de la cola
		int r = pos.front().first;
		int c = pos.front().second;
		imprime(ma, pos);
		pos.pop();
		

		//Imprime matriz y cola
		cout << endl;
		
		//Miramos si estamos en un tesoro
		if(ma[r][c]%2) return (ma[r][c]-1)/2;
		else{

			//Miramos si la siguiente posición es válida y la guardamos en la
			if(on_range(ma, r+1, c) and ma[r+1][c] != -1){
				if(ma[r+1][c] == 1 or not ma[r+1][c] >= ma[r][c])ma[r+1][c] += ma[r][c];
				ma[r+1][c] += 2;
				pos.push(make_pair(r+1, c));
			}
			if(on_range(ma, r, c+1) and ma[r][c+1] != -1){
				if(ma[r][c+1] == 1 or not ma[r][c+1] >= ma[r][c])ma[r][c+1] += ma[r][c];
				ma[r][c+1] += 2;
				pos.push(make_pair(r, c+1));
			}
			if(on_range(ma, r-1, c) and ma[r-1][c] != -1){
				if(ma[r-1][c] == 1 or not ma[r-1][c] >= ma[r][c])ma[r-1][c] += ma[r][c];
				ma[r-1][c] += 2;
				pos.push(make_pair(r-1, c));
			}
			if(on_range(ma, r, c-1) and ma[r][c-1] != -1){
				if(ma[r][c-1] == 1 or not ma[r][c-1] >= ma[r][c])ma[r][c-1] += ma[r][c];
				ma[r][c-1] += 2;
				pos.push(make_pair(r, c-1));
			}
			
			//Ponemos la posición como visitada
			ma[r][c] = -1;
			//Tratamos la siguiente posición
			return bfs(ma, pos);
		}
	}
}

//Función principal
int main(){
	//Leer entrada
	int rows, cols;
	cin >> rows >> cols;

	//Leer entrada
	char x;
	Matrix ma(rows, vector<int>(cols));
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < cols; ++j){
			cin >> x;
			if(x == 'X') ma[i][j] = -1;
			else if(x == 't') ma[i][j] = 1;
			else ma[i][j] = 0;
		}
	}

	//Leer entrada
	int irow, icol;
	cin >> irow >> icol;

	//Preparo la cola con la primera posición
	Position pos;
	pos.push(make_pair(irow-1, icol-1));
	
	//Calculo la distancia
	int dist = bfs(ma, pos);

	//Miro si la distancia es un valor válido y imprimo el resultado
	if(dist < 0) cout << "no treasuer can be reached" << endl;
	else cout << "minimum distance: " << dist << endl;
}
