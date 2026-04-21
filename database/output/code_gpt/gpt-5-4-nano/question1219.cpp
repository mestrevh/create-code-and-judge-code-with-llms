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
    vector<long long> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    string func;
    getline(cin, func);
    string x, op, y;
    while (cin >> x >> op >> y) break;

    long long res = a.back();
    for (int i = N - 2; i >= 0; --i) {
        if (op == "+") res = a[i] + res;
        else res = a[i] - res;
    }

    cout << res << "\n";
    return 0;
}