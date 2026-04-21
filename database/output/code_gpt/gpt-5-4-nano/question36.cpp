/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long M, N;
    if (!(cin >> M >> N)) return 0;

    if (M <= 0) return 0;

    long long k = N / M;
    if (k == 0) {
        cout << "sem multiplos menores que " << N;
    } else {
        cout << k * M;
    }
    return 0;
}