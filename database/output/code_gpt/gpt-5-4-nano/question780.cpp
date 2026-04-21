/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<int> q;
    vector<bool> in(10001, false);

    string cmd;
    while (cin >> cmd) {
        if (cmd == "a") {
            int x; cin >> x;
            if (!in[x]) {
                in[x] = true;
                q.push_back(x);
            }
        } else if (cmd == "r") {
            int x; cin >> x;
            if (in[x]) {
                in[x] = false;
                for (auto it = q.begin(); it != q.end(); ++it) {
                    if (*it == x) {
                        q.erase(it);
                        break;
                    }
                }
                cout << "removido\n";
            } else {
                cout << "falha\n";
            }
        } else if (cmd == "p") {
            if (q.empty()) {
                cout << "vazia\n";
            } else {
                for (size_t i = 0; i < q.size(); i++) {
                    if (i) cout << ' ';
                    cout << q[i];
                }
                cout << "\n";
            }
        }
    }
    return 0;
}