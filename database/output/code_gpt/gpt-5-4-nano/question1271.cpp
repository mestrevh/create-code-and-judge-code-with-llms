/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    if (!(cin >> N >> M)) return 0;

    int width = 3;

    long long digitsN = to_string(N).size();
    width = (int)max<long long>(3, digitsN);

    for (long long i = 1; i <= N; i++) {
        cout << setw(width) << i;
        if (i % M == 0) cout << "\n";
    }
    if (N % M != 0) cout << "\n";
    return 0;
}