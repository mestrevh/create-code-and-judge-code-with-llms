/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    if (!(cin >> K)) return 0;

    set<int> scores;
    unordered_set<string> names;
    unordered_map<int, string> scoreToName;

    for (int i = 0; i < K; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "ADD") {
            string N;
            int P;
            cin >> N >> P;

            if (names.find(N) != names.end()) {
                cout << N << " ja esta no sistema.\n";
            } else {
                names.insert(N);
                if (scores.find(P) != scores.end()) {
                    string existingName = scoreToName[P];
                    names.erase(existingName);
                    scoreToName.erase(P);
                    scores.erase(P);
                }
                scores.insert(P);
                scoreToName[P] = N;
                cout << N << " inserido com sucesso!\n";
            }
        } else if (cmd == "PROX") {
            int P;
            cin >> P;

            if (scores.find(P) == scores.end()) continue;

            auto it = scores.find(P);
            string N = scoreToName[P];

            bool hasPred = false, hasSucc = false;
            int predP = -1, succP = -1;

            if (it != scores.begin()) {
                auto itPred = prev(it);
                hasPred = true;
                predP = *itPred;
            }
            auto itSucc = next(it);
            if (itSucc != scores.end()) {
                hasSucc = true;
                succP = *itSucc;
            }

            if (!hasPred && !hasSucc) {
                cout << "Apenas " << N << " existe no sistema...\n";
            } else if (!hasPred && hasSucc) {
                cout << N << " e o menor! e logo apos vem " << scoreToName[succP] << "\n";
            } else if (hasPred && !hasSucc) {
                cout << N << " e o maior! e logo atras vem " << scoreToName[predP] << "\n";
            } else {
                cout << N << " vem apos " << scoreToName[predP] << " e antes de " << scoreToName[succP] << "\n";
            }
        }
    }

    return 0;
}