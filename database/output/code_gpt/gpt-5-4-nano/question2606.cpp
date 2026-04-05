/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        string a, b;
        cin >> a >> b;

        bool ok = false;
        array<bool, 256> seen{};
        seen.fill(false);
        for (unsigned char ch : a) seen[ch] = true;
        for (unsigned char ch : b) {
            if (seen[ch]) {
                ok = true;
                break;
            }
        }

        if (ok) cout << "Compartilham Substring\n";
        else cout << "Nao Compartilham Substring\n";
    }
    return 0;
}