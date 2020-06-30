#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matrix;

//Función de multiplicación de matrices
Matrix mult(const Matrix& A, const Matrix& B, int& mod){
	Matrix aux(2, vector<int>(2, 0));
	for(int fila = 0; fila < aux.size(); ++fila){
		for(int columna = 0; columna < aux.size(); ++columna){
			for(int variable = 0; variable < A.size(); ++variable)
				aux[fila][columna] += A[fila][variable]*B[variable][columna];
			aux[fila][columna] %= mod;
		}
	}
	return aux;
}

//Función recursiva de multiplicación
Matrix power(const Matrix& M, const int exp, int& mod){
	if(exp == 0) return {{1, 0}, {0, 1}};
	else{
		Matrix aux = power(M, exp/2, mod);
		if(exp%2){
			Matrix product = mult(aux, aux, mod);
			return mult(M, product, mod);
		}
		else return mult(aux, aux, mod);
	}
}

//Escribe la matriz
void write_matrix(const Matrix& M){
	for(int fila = 0; fila < M.size(); ++fila){
		for(int columna = 0; columna < M.size(); ++columna){
			cout << M[fila][columna];
			if(columna != M.size() -1) cout << ' ';
		}
		cout << endl;
	}
	cout << "----------" << endl;
}

//Función principal
int main(){
	//Leemos los valores de la entrada
	Matrix M(2, vector<int> (2));
	while(cin >> M[0][0]){
		cin >> M[0][1] >> M[1][0] >> M[1][1];
		int exp, mod;
		cin >> exp >> mod;
		//Calculamos M^n donde sus valores M[fila][columna] estaran en módulo 100
		Matrix Result = power(M, exp, mod);

		//Escribimos la matriz resultante
		write_matrix(Result);
	}
}
