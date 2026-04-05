/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> st;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "Finalizar") break;
        if (cmd == "Empilhar") {
            long long x;
            cin >> x;
            st.push_back(x);
        } else if (cmd == "Desempilhar") {
            if (!st.empty()) st.pop_back();
        } else if (cmd == "Imprimir") {
            for (int i = (int)st.size() - 1; i >= 0; --i) {
                if (i != (int)st.size() - 1) cout << ' ';
                cout << st[i];
            }
            cout << '\n';
        }
    }
    return 0;
}