/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long N;
    if (!(cin >> N)) return 0;

    auto fib = [&](auto&& self, unsigned long long n) -> unsigned long long {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return self(self, n - 1) + self(self, n - 2);
    };

    unsigned long long c = fib(fib, N);

    if (c == 0) cout << "O antidoto nao e necessario";
    else cout << c << " mg/L";
    return 0;
}