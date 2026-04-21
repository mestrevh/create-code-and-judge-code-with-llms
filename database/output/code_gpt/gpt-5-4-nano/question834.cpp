/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c, d;
    if (!(cin >> a >> b >> c >> d)) return 0;

    auto build = [&](long long x) -> long long {
        return x * x + x;
    };

    long long ab = build(a);
    long long cd = build(d);

    string s = to_string(ab + cd + b + c);
    cout << s << "\n";
    return 0;
}