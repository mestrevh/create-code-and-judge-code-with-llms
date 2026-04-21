/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    if (!(cin >> K)) return 0;

    map<string, int> name_to_score;
    map<int, string> score_to_name;

    for (int i = 0; i < K; ++i) {
        string cmd;
        if (!(cin >> cmd)) break;
        if (cmd == "ADD") {
            string name;
            int score;
            cin >> name >> score;
            if (name_to_score.find(name) != name_to_score.end()) {
                cout << name << " ja esta no sistema.\n";
            } else {
                name_to_score[name] = score;
                score_to_name[score] = name;
                cout << name << " inserido com sucesso!\n";
            }
        } else if (cmd == "PROX") {
            int score;
            cin >> score;
            auto it = score_to_name.find(score);
            if (it == score_to_name.end()) continue;

            string name = it->second;
            bool has_pre = (it != score_to_name.begin());
            auto next_it = next(it);
            bool has_suc = (next_it != score_to_name.end());

            if (!has_pre && !has_suc) {
                cout << "Apenas " << name << " existe no sistema...\n";
            } else if (!has_pre && has_suc) {
                cout << name << " e o menor! e logo apos vem " << next_it->second << "\n";
            } else if (has_pre && !has_suc) {
                cout << name << " e o maior! e logo atras vem " << prev(it)->second << "\n";
            } else {
                cout << name << " vem apos " << prev(it)->second << " e antes de " << next_it->second << "\n";
            }
        }
    }

    return 0;
}