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

    vector<bool> isPrime(600000, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; 1LL * i * i < (int)isPrime.size(); ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < (int)isPrime.size(); j += i) isPrime[j] = false;
        }
    }

    int count = 0;
    for (int i = 2; i < (int)isPrime.size(); ++i) {
        if (isPrime[i]) {
            cout << i << "\n";
            if (++count == N) break;
        }
    }
    return 0;
}