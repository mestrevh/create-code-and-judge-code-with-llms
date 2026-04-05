/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    long double total = 0.0L;
    long long used = 0;

    const long long box = 12;
    const long double price = 7.89L;

    bool first = true;
    while (cin >> n) {
        if (n % 2 == 1) break;
        used += n;
        total += (n / box) * price;
        long long rem = n % box;
        if (rem > 0) total += price;
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(2) << (double)total << "\n";
    cout << used % box << "\n";
    return 0;
}