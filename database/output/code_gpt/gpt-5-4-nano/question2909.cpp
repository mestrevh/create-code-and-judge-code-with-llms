/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    if (!(cin >> Q)) return 0;
    while (Q--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];

        vector<int> pos(n + 1);
        for (int i = 0; i < n; i++) pos[p[i]] = i;

        int start = pos[1];
        bool okH = true;
        for (int x = 1; x < n; x++) {
            int expected = x + 1;
            int idx = (start + (x - 1)) % n;
            if (p[idx] != expected) { okH = false; break; }
        }
        if (okH) {
            cout << "SIM, HORARIO\n";
            continue;
        }

        bool okA = true;
        for (int x = n; x > 1; x--) {
            int expected = x - 1;
            int idx = (start + (n - x)) % n;
            if (p[idx] != expected) { okA = false; break; }
        }
        if (okA) cout << "SIM, ANTI-HORARIO\n";
        else cout << "NAO\n";
    }
    return 0;
}