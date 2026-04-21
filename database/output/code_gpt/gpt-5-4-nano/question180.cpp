/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, C;
    if (!(cin >> N >> C)) return 0;

    long long cur = 0;
    for (int i = 0; i < N; i++) {
        long long S, E;
        cin >> S >> E;
        cur -= S;
        cur += E;
        if (cur > C) {
            cout << 'S' << "\n";
            return 0;
        }
    }
    cout << 'N' << "\n";
    return 0;
}