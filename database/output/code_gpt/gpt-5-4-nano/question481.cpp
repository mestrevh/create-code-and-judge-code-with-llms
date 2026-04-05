/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long x;
    if (!(cin >> x)) return 0;

    vector<long long> small, large;
    for (long long i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            small.push_back(i);
            long long j = x / i;
            if (j != i) large.push_back(j);
        }
    }

    for (int i = (int)large.size() - 1; i >= 0; --i) {
        cout << large[i] << "\n";
    }
    for (int i = (int)small.size() - 1; i >= 0; --i) {
        cout << small[i] << "\n";
    }

    return 0;
}