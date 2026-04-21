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

    vector<int> digits;
    int x = N;
    while (x > 0) {
        digits.push_back(x % 10);
        x /= 10;
    }
    if (digits.empty()) digits.push_back(0);

    vector<int> fact(10, 1);
    for (int i = 1; i <= 9; i++) {
        fact[i] = fact[i - 1] * i;
    }

    int sum = 0;
    for (int d : digits) sum += fact[d];

    if (sum == N) {
        cout << "S\n";
    } else {
        cout << N << "\n" << sum << "\n";
    }
    return 0;
}