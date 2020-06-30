#include <iostream>
#include <map>

using namespace std;

void addGame(const string& game, map<string,int>& m) {
  ++m[game];
}

bool canBuy(const string& game, map<string,int>& m, int totalGames){
  return (m[game] + 1 <= totalGames - m[game]);
}

int main(){
  int n;
  while (cin >> n) {

    map<string,int> m;
    int totalGames = n;
    for (int i = 0; i < n; ++i) {
      string game; cin >> game;
      addGame(game,m);
    }

    int g; cin >> g;
    for (int i = 0; i < g; ++i) {
      string game; cin >> game;
      if (canBuy(game,m,totalGames)){
	addGame(game,m);
	++totalGames;
      }
    }

    for (auto& g:m) cout << g.first << " " << g.second << endl;
    cout << string(20, '-') << endl;
  }
}
