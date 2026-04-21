/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<long long> q;
    string cmd;

    while (cin >> cmd) {
        if (cmd == "Finalizar") break;
        if (cmd == "Enfileirar") {
            long long x;
            cin >> x;
            q.push(x);
        } else if (cmd == "Desenfileirar") {
            if (!q.empty()) q.pop();
        } else if (cmd == "Imprimir") {
            bool first = true;
            queue<long long> tmp = q;
            while (!tmp.empty()) {
                if (!first) cout << ' ';
                first = false;
                cout << tmp.front();
                tmp.pop();
            }
            cout << "\n";
        }
    }
    return 0;
}