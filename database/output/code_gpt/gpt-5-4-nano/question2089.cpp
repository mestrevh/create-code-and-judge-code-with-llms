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

    auto sumSquares = [](int x) {
        int s = 0;
        while (x > 0) {
            int d = x % 10;
            s += d * d;
            x /= 10;
        }
        return s;
    };

    int x = N;
    unordered_set<int> seen;
    while (true) {
        if (x == 1) {
            cout << "S\n";
            return 0;
        }
        if (seen.count(x)) {
            cout << N << "\n";
            return 0;
        }
        seen.insert(x);
        x = sumSquares(x);
    }
}