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

    long long pos = 1;
    long long moves = 0;
    int d = 1;

    while (pos != N) {
        moves++;
        pos += d;
        d++;
        if (d == 7) d = 1;

        if (pos > N) pos = (pos - 1) % N + 1;
    }

    cout << moves << "\n";
    return 0;
}