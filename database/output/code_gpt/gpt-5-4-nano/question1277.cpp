/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    bool ok = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            long long v;
            cin >> v;
            if (j < i && v != 0) ok = false;
        }
    }

    cout << (ok ? "true" : "false");
    return 0;
}