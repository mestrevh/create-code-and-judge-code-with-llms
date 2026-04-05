/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> compras = {"leite", "manteiga", "ovos"};

    string adicionar, remover;
    if (!getline(cin, adicionar)) return 0;
    getline(cin, remover);

    if (!adicionar.empty() && adicionar.back() == '\r') adicionar.pop_back();
    if (!remover.empty() && remover.back() == '\r') remover.pop_back();

    compras.push_back(adicionar);

    auto it = find(compras.begin(), compras.end(), remover);
    if (it != compras.end()) compras.erase(it);

    cout << "[";
    for (size_t i = 0; i < compras.size(); i++) {
        if (i) cout << ", ";
        cout << "'" << compras[i] << "'";
    }
    cout << "]";
    return 0;
}