/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    int k;
    cin >> k;

    map<int, string> score_name;
    set<pair<int, string>> players;

    for (int i = 0; i < k; ++i) {
        string command;
        cin >> command;

        if (command == "ADD") {
            string name;
            int score;
            cin >> name >> score;

            if (players.find({score, name}) != players.end()) {
                cout << name << " ja esta no sistema." << endl;
            } else {
                score_name[score] = name;
                players.insert({score, name});
                cout << name << " inserido com sucesso!" << endl;
            }
        } else if (command == "PROX") {
            int score;
            cin >> score;

            if (score_name.find(score) == score_name.end()) {
                continue; 
            }

            string name = score_name[score];
            auto it = players.find({score, name});

            if (players.size() == 1) {
                cout << "Apenas " << name << " existe no sistema..." << endl;
            } else if (it == players.begin()) {
                auto next = next(it);
                cout << name << " e o menor! e logo apos vem " << next->second << endl;
            } else if (next(it) == players.end()) {
                auto prev = prev(it);
                cout << name << " e o maior! e logo atras vem " << prev->second << endl;
            } else {
                auto next = next(it);
                auto prev = prev(it);
                cout << name << " vem apos " << prev->second << " e antes de " << next->second << endl;
            }
        }
    }

    return 0;
}
