/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N, K;
    if (!(cin >> N)) return 0;
    if (!(cin >> K)) return 0;

    if (N == 1) {
        cout << (K > 0 ? K : 0) << "\n";
        return 0;
    }

    long long h = 0;
    __int128 prod = 1;
    while (true) {
        if (prod == K) {
            cout << h << "\n";
            return 0;
        }
        if (prod > K / N) break;
        prod *= N;
        h++;
    }

    cout << -1 << "\n";
    return 0;
}