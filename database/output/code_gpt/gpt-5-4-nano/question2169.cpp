/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<int> pedidos;
    char op;
    while (cin >> op) {
        if (op == 's') break;
        if (op == 'p') {
            if (pedidos.empty()) {
                cout << "vazia";
            } else {
                bool first = true;
                for (int x : pedidos) {
                    if (!first) cout << ' ';
                    cout << x;
                    first = false;
                }
            }
            cout << "\n";
        } else {
            int x;
            cin >> x;
            if (op == 'a') {
                pedidos.insert(x);
            } else if (op == 'r') {
                auto it = pedidos.find(x);
                if (it != pedidos.end()) {
                    pedidos.erase(it);
                    cout << "removido\n";
                } else {
                    cout << "falha\n";
                }
            }
        }
    }
    return 0;
}