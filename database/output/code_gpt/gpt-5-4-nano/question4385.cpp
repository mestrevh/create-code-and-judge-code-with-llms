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
    long long cap;
    if (!(cin >> N)) return 0;
    if (!(cin >> cap)) return 0;

    while (N > 0) {
        long long take = min<long long>(N, cap);
        cout << take << "\n";
        N -= (int)take;
    }
    return 0;
}