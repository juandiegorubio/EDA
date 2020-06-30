#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;
typedef map<int, VI> Graph;


bool mirar_ciclos(Graph& g, VB& visit, int nodo, int previo){
    // Encontramos ciclo
    if(visit[nodo]) return true;

    visit[nodo] = true;
    VI adyacentes = g[nodo];
    bool ciclo = false;
    int i = 0;
    // Miramos si los adyacentes llevan a un ciclo
    while(i < adyacentes.size() and not ciclo){
        if(adyacentes[i] != previo) ciclo = mirar_ciclos(g, visit, adyacentes[i], nodo);
        ++i;
    }
    return ciclo;
}


void imprime_grafo(Graph g){
    for(pair<int, VI> i : g){
        cout << i.first << ": ";
        for(int j = 0; j < i.second.size(); ++j) cout << i.second[j] << ' ';
        cout << endl;
    }
}


int main(){
    int v, e;
    while(cin >> v >> e){
        Graph g;
        VB visitados(v);
        // Guardamos los nodos
        for(int i = 0; i < v; ++i){
            g[i] = VI (0);
            visitados[i] = false;
        }
        // Guardamos las aristas
        for(int i = 0; i < e; ++i){
            int node1, node2;
            cin >> node1 >> node2;
            g[node1].push_back(node2);
            g[node2].push_back(node1);
        }

        int i = 0;
        int trees = 0;
        bool ciclo = false;
        while(i < v and not ciclo){
            if(not visitados[i]){
                ciclo = mirar_ciclos(g, visitados, i, i);
                ++trees;
            }
            ++i;
        }
        if(ciclo) cout << "no" << endl;
        else cout << trees << endl;
    }
}
