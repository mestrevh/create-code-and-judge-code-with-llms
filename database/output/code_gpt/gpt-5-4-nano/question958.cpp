/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

string formatar_dinheiro(double valor) {
    const long double x = static_cast<long double>(valor) + 1e-12L;
    long long cents = llround(x * 100.0L);
    long long inteiro = cents / 100;
    int dec = static_cast<int>(cents % 100);

    string s = to_string(inteiro);
    for (int i = (int)s.size() - 3; i > 0; i -= 3) s.insert(i, ".");
    ostringstream oss;
    oss << "R$ " << s << ',' << setw(2) << setfill('0') << dec;
    return oss.str();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double v;
    if (!(cin >> v)) return 0;
    cout << formatar_dinheiro(v) << "\n";
    return 0;
}