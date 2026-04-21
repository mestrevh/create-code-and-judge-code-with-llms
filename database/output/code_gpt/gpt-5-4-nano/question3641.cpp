/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<pair<string,int>> pessoas;
    pessoas.reserve(N);

    for (int i = 0; i < N; i++) {
        string nome;
        int G;
        cin >> nome >> G;
        pessoas.push_back({nome, G});
    }

    stable_sort(pessoas.begin(), pessoas.end(), [](const auto& a, const auto& b){
        return (a.second % 2) < (b.second % 2);
    });

    for (int i = 0; i < N; i++) {
        if (i) cout << "\n";
        cout << pessoas[i].first;
    }
    return 0;
}