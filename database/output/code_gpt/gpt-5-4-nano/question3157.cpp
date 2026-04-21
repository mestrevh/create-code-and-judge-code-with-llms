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
    long long X;
    if (!(cin >> N >> X)) return 0;

    int first = (int)((X % 2 + 2) % 2);
    while (first == X) first ^= 1;

    int ones = N - 1;
    long long xorRest = ((ones % 2) ? 1LL : 0LL);
    long long totalXor = (first ^ xorRest);
    if (totalXor != X) {
        ones = N - 2;
    }

    int zeros = (N - 1) - ones;

    cout << first;
    for (int i = 0; i < zeros; i++) cout << " 0";
    for (int i = 0; i < ones; i++) cout << " 1";
    cout << "\n";
    return 0;
}