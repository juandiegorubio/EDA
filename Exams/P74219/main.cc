#include <iostream>
#include <queue>
using namespace std;

typedef vector<vector<int>> Matrix;

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

int main(){
  int n, m;
  while(cin >> n >> m){
    if(n == 0) cout << 0 << endl;
    else{
      Matrix Fib = {{1, 1}, {1, 0}};
      Matrix aux = Fib;
      if(n > 1)
        aux = power(Fib, n-1, m);
      cout << aux[0][0] << endl;
    }
  }
}
