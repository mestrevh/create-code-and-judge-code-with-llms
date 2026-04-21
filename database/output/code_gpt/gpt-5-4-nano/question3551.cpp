/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "nao eh triangulo";
        return 0;
    }

    vector<long long> s = {a, b, c};
    sort(s.begin(), s.end());

    if (s[0] + s[1] <= s[2]) {
        cout << "nao eh triangulo";
        return 0;
    }

    if (a == b && b == c) {
        cout << "eh equilatero";
    } else if (a == b || a == c || b == c) {
        cout << "eh isosceles";
    } else {
        cout << "eh escaleno";
    }

    return 0;
}