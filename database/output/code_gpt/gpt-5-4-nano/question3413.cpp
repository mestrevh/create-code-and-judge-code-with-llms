/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;

    bool first = true;
    for (long long i = 0; i <= N; i += 2) {
        if (!first) cout << "   ";
        cout << i;
        first = false;
    }
    return 0;
}