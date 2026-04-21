/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, E;
    if (!(cin >> N >> E)) return 0;

    unordered_set<int> seen;
    seen.reserve(N * 2);

    for (int i = 0; i < N; i++) {
        int g;
        cin >> g;
        if (seen.find(E - g) != seen.end()) {
            cout << "SIM";
            return 0;
        }
        seen.insert(g);
    }

    cout << "NAO";
    return 0;
}