/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long grains;
    if (!(cin >> grains)) return 0;

    string op;
    long long n;
    bool winter = false;

    while (cin >> op >> n) {
        if (op == "GUARDAR") {
            grains += n;
        } else if (op == "RETIRAR") {
            if (n > grains) {
                winter = true;
                break;
            }
            grains -= n;
        }
    }

    if (winter) cout << "Winter is here\n";
    else cout << grains << "\n";
    return 0;
}