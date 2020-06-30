#include <iostream>
#include <queue>
#include <map>
#include <utility>
using namespace std;

typedef pair<string, int> Player;

struct PlayerComp{
    bool operator()(const Player& A, const Player& B){
        if(A.second == B.second) return A.first > B.first;
        else return A.second < B.second;
    }
};

int main(){
    priority_queue<Player, vector<Player>, PlayerComp> players_ever;
    map<string, pair<int, bool>> players;
    string option;
    string player1;
    while(cin >> option >> player1){
        if(option == "LOGIN"){
            auto it = players.find(player1);
            if(it == players.end()) players[player1] = make_pair(1200, true);
            else it->second.second = true;
        }

        else if(option == "LOGOUT"){
            if(players.find(player1) != players.end()) players[player1].second = false;
        }

        else{
            bool plays1 = (players.find(player1) != players.end() and players[player1].second);
            if(option == "PLAY"){
                string player2;
                cin >> player2;
                bool plays2 = (players.find(player2) != players.end() and players[player2].second);

                if(plays1 and plays2){
                    players[player1].first+=10;
                    if(players[player2].first >= 1210) players[player2].first-=10;
                }
                else cout << "player(s) not connected" << endl;
            }

            else{
                auto it = players.find(player1);
                if(it != players.end()) cout << it->first << ' ' << it->second.first << endl;
                else cout << "player(s) not connected" << endl;
            }
        }
    }

    for(auto it : players){
        Player aux = {it.first, it.second.first};
        players_ever.push(aux);
    }
    cout << endl << "RANKING" << endl;
    while(players_ever.size()){
        Player aux = players_ever.top();
        players_ever.pop();
        cout << aux.first << ' ' << aux.second << endl;
    }
}
