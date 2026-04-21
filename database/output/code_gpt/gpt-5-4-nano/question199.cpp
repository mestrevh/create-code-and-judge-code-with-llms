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
    long long total = 0;
    for (int i = 0; i < N; i++) {
        long long T, V;
        cin >> T >> V;
        total += T * V;
    }
    cout << total << "\n";
    return 0;
}