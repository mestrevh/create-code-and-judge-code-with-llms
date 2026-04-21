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

    map<char, long long> sums;
    long long total = 0;

    for (int i = 0; i < N; i++) {
        char A;
        long long B;
        cin >> A >> B;
        sums[A] += B;
        total += B;
    }

    for (auto &p : sums) {
        cout << p.first << ' ' << p.second << "\n";
    }
    cout << "TOTAL " << total << "\n";
    return 0;
}