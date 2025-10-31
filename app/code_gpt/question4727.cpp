/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int K;
    cin >> K;
    map<int, string> players;
    map<string, int> scores;
    
    while (K--) {
        string command;
        cin >> command;
        if (command == "ADD") {
            string name;
            int score;
            cin >> name >> score;
            if (scores.count(name)) {
                cout << name << " ja esta no sistema." << endl;
            } else {
                players[score] = name;
                scores[name] = score;
                cout << name << " inserido com sucesso!" << endl;
            }
        } else if (command == "PROX") {
            int score;
            cin >> score;
            if (!scores.count(score)) {
                cout << "Apenas " << players.lower_bound(score)->second << " existe no sistema..." << endl;
                continue;
            }
            string name = players[score];
            auto it = players.find(score);
            auto pre = it == players.begin() ? players.end() : prev(it);
            auto suc = next(it);
            if (pre == players.end() && suc == players.end()) {
                cout << "Apenas " << name << " existe no sistema..." << endl;
            } else if (pre == players.end()) {
                cout << name << " e o menor! e logo apos vem " << suc->second << endl;
            } else if (suc == players.end()) {
                cout << name << " e o maior! e logo atras vem " << pre->second << endl;
            } else {
                cout << name << " vem apos " << pre->second << " e antes de " << suc->second << endl;
            }
        }
    }
    return 0;
}
