/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 20; i++) {
        long long val = 1LL * i * i;
        cout << val;
        if (i + 1 < 20) cout << "\n";
    }
    return 0;
}