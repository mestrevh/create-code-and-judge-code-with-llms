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

    long long x = llabs(N);
    int sum = 0;
    if (x == 0) sum = 0;
    while (x > 0) {
        sum += int(x % 10);
        x /= 10;
    }

    vector<long long> fib;
    fib.push_back(0);
    fib.push_back(1);
    while (true) {
        long long next = fib[fib.size() - 1] + fib[fib.size() - 2];
        if (next > 1000000) break;
        fib.push_back(next);
    }

    bool ok = binary_search(fib.begin(), fib.end(), (long long)sum);
    cout << (ok ? "Sim" : "Nao");
    return 0;
}