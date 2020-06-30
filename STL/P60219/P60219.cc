#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool comp(string a, string b){
    if(a.size() == b.size()) return b < a;
    else return b.size() < a.size();
}

int main(){
    unordered_set<string> has;
    unordered_set<string> had;
    int i = 1;
    string word;
    cin >> word;

    while(word != "QUIT"){
        if(word == "END"){
            cout << "GAME #" << i << endl;

            sort(has.begin(), has.end(), comp);
            cout << "HAS:" << endl;
            for(auto it : has) cout << it << endl;
            cout << endl;

            cout << "HAD:" << endl;
            for(auto it : had) cout << it << endl;
            cout << endl;

            has.clear();
            had.clear();
            ++i;
        }

        else{
            if(has.find(word) == has.end()){
                has.insert(word);
                if(had.find(word) != had.end()) had.erase(word);
            }
            else{
                had.insert(word);
                has.erase(word);
            }
        }
        cin >> word;
    }
    cout << "GAME #" << i << endl;

    sort(has.begin(), has.end(), comp);
    cout << "HAS:" << endl;
    for(auto it : has) cout << it << endl;
    cout << endl;

    cout << "HAD:" << endl;
    for(auto it : had) cout << it << endl;

}
