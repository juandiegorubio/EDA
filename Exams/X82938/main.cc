#include <iostream>
#include <vector>
using namespace std;

//Mira en la parte decreciente
// v[i] >= x >= v[f]
bool decreix(int x, const vector<int>& v, int i, int f){
  if(i > f) return false;
  int m = (i+f)/2;
  if(v[m] == x) return true;
  if(x > v[m]) return decreix(x, v, i, m-1);
  return decreix(x, v, m+1, f);
}

//Mira en la parte creciente
// v[i] <= x <= v[f]
bool creix(int x, const vector<int>& v, int i, int f){
  if(i > f) return false;
  int m = (i+f)/2;
  if(v[m] == x) return true;
  if(v[m] > x) return creix(x, v, i, m-1);
  return creix(x, v, m+1, f);
}


//Encuentra el top
int encuentra_top(const vector<int>& v, int i, int f){
  //Las posiciones convergen al top
  if(i == f) return i;
  if(f-i == 1){
    if(v[i] > v[f]) return i;
    else return f;
  }
  int m = (i+f)/2;
  // v[m] es el top
  if(v[m-1] < v[m] and v[m] > v[m+1]) return m;
  // m < top <= f
  if(v[m-1] < v[m]) return encuentra_top(v, m+1, f);
  // i <= top < m
  return encuentra_top(v, i, m-1);
}

//Busca el elemento x en el vector v
bool search(int x, const vector<int>& v){
  //Encuentra el top
  int top = encuentra_top(v, 0, v.size()-1);
  //Si el top es el valor que buscamos
  if(x == v[top]) return true;
  //Si el elemento es mayor que el top o menos que los extremos -> no existe en el vector
  if(x > v[top]) return false;
  //El elemento no es mayor que el top -> puede existir en el vector
  return creix(x, v, 0, top-1) || decreix(x, v, top+1, v.size()-1);
}
