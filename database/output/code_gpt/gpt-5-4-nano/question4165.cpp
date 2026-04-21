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
    long long result = 0;

    auto isPrimeOdd = [](long long x) -> bool {
        if (x <= 1 || x % 2 == 0) return false;
        for (long long i = 3; i * i <= x; i += 2) {
            if (x % i == 0) return false;
        }
        return true;
    };

    for (int i = 0; i < N; i++) {
        long long a;
        cin >> a;
        if (isPrimeOdd(a)) result -= a;
        else result += a;
    }

    if (result > 0) {
        cout << "Ele ainda tem " << result << " dias de vida";
    } else if (result < 0) {
        cout << "Foi de base";
    } else {
        cout << "Foi de base";
    }
    return 0;
}