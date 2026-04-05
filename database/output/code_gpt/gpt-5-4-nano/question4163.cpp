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

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ( (i + j) % 2 == 0 ) cout << 'A';
            else cout << '.';
        }
        if (i + 1 < N) cout << "\n";
    }
    return 0;
}