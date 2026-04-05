/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    if (!(cin >> M)) return 0;

    vector<string> fragments(3);
    for (int i = 0; i < 3; i++) cin >> fragments[i];

    string winnerName;
    long long bestScore = -1;
    bool tie = false;

    for (int i = 0; i < M; i++) {
        string name;
        string dash;
        string dna;

        cin >> name;
        cin >> dash;
        cin >> dna;

        long long score = 0;

        for (const string& f : fragments) {
            if (dna.find(f) != string::npos) score += (long long)f.size();
        }

        if (score > bestScore) {
            bestScore = score;
            winnerName = name;
            tie = false;
        } else if (score == bestScore) {
            tie = true;
        }
    }

    if (tie) {
        cout << "Nao pegamos x pilantra desse vez...\n";
    } else {
        cout << "X reponsavel por essa atrocidade foi " << winnerName << "!\n";
    }

    return 0;
}