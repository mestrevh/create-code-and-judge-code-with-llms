/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b;
    cout << "Digite o valor do primeiro cateto:\n";
    if (!(cin >> a)) return 0;
    cout << "Digite o valor do segundo cateto:\n";
    if (!(cin >> b)) return 0;

    if (a <= 0 || b <= 0) {
        cout << "Valor de cateto invalido.";
        return 0;
    }

    double h = sqrt(a * a + b * b);

    cout << fixed;
    cout << setprecision(10);
    while (!cout.fail() && h != 0 && fabs(h - round(h)) < 1e-9) {
        break;
    }

    ostringstream oss;
    oss << fixed << setprecision(10) << h;
    string s = oss.str();
    if (s.find('.') != string::npos) {
        while (!s.empty() && s.back() == '0') s.pop_back();
        if (!s.empty() && s.back() == '.') s.pop_back();
    }

    ostringstream oa, ob;
    oa << fixed << setprecision(10) << a;
    ob << fixed << setprecision(10) << b;

    string sa = oa.str(), sb = ob.str();
    if (sa.find('.') != string::npos) {
        while (!sa.empty() && sa.back() == '0') sa.pop_back();
        if (!sa.empty() && sa.back() == '.') sa.pop_back();
    }
    if (sb.find('.') != string::npos) {
        while (!sb.empty() && sb.back() == '0') sb.pop_back();
        if (!sb.empty() && sb.back() == '.') sb.pop_back();
    }

    cout << "O triangulo cujos catetos sao " << sa << " e " << sb << " tem hipotenusa " << s << ".";
    return 0;
}