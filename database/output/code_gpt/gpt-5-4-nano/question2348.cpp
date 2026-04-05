/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

bool buscaEmLista(int x, list<int>& L, size_t n) {
    for (auto it = L.begin(); it != L.end(); ++it) {
        if (*it == x) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    if (!(cin >> x)) return 0;

    size_t n;
    cin >> n;

    list<int> L(n);
    auto it = L.begin();
    for (size_t i = 0; i < n; i++) {
        cin >> *it;
        ++it;
    }

    bool found = buscaEmLista(x, L, n);
    cout << (found ? "sim" : "nao") << "\n";
    return 0;
}