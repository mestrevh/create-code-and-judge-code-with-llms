/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Child {
    string nome;
    long long p;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<Child> v;
    v.reserve(N);

    for (int i = 0; i < N; i++) {
        string nome;
        long long base;
        long long o, b, r, p;
        cin >> nome >> base >> o >> b >> r >> p;
        long long score = base + o * 5 + b * 3 + r * (-3) + p * (-5);
        v.push_back({nome, score});
    }

    sort(v.begin(), v.end(), [](const Child& a, const Child& b) {
        if (a.p != b.p) return a.p > b.p;
        return a.nome < b.nome;
    });

    for (const auto& c : v) {
        cout << c.nome << ' ' << c.p << "\n";
    }
    return 0;
}