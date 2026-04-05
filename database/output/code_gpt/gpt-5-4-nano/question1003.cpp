/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> sorteados(10);
    for (int i = 0; i < 10; i++) {
        if (!(cin >> sorteados[i])) return 0;
    }

    int N;
    cin >> N;

    const int PICK_SIZE = 15;
    vector<int> inA(51, 0);

    for (int i = 1; i <= 50; i++) inA[i] = 0;

    multiset<string> winnersA1; // not used, just to avoid warnings
    (void)winnersA1;

    vector<string> faixaA_codes;
    vector<string> faixaB_codes;

    int best = INT_MAX, worst = INT_MIN;

    vector<pair<int,string>> candidates; 
    candidates.reserve(N);

    int maxMatch = -1, minMatch = 1000000;

    for (int i = 0; i < N; i++) {
        string code;
        cin >> code;
        vector<int> chosen(PICK_SIZE);
        for (int j = 0; j < PICK_SIZE; j++) cin >> chosen[j];

        for (int x : chosen) inA[x] = 1;
        int matches = 0;
        for (int v : sorteados) matches += inA[v];
        for (int x : chosen) inA[x] = 0;

        if (matches > maxMatch) maxMatch = matches;
        if (matches < minMatch) minMatch = matches;

        candidates.push_back({matches, code});
    }

    for (auto &p : candidates) {
        if (p.first == maxMatch) faixaA_codes.push_back(p.second);
        if (p.first == minMatch) faixaB_codes.push_back(p.second);
    }

    cout << "Faixa: " << maxMatch << " acertos\n";
    for (auto &s : faixaA_codes) cout << s << "\n";
    cout << faixaA_codes.size() << " ganhadores\n\n";
    cout << "Faixa: " << minMatch << " acertos\n";
    for (auto &s : faixaB_codes) cout << s << "\n";
    cout << faixaB_codes.size() << " ganhador";
    if (faixaB_codes.size() != 1) cout << "es";
    return 0;
}