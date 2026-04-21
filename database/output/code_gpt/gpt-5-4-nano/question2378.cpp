/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Complexo {
    double a;
    double b;
};

Complexo soma(const Complexo& z1, const Complexo& z2) {
    return {z1.a + z2.a, z1.b + z2.b};
}

Complexo mult(const Complexo& z1, const Complexo& z2) {
    return {z1.a * z2.a - z1.b * z2.b, z1.a * z2.b + z2.a * z1.b};
}

static string formatReal(double x) {
    if (fabs(x) < 0.0000000005) x = 0;
    ostringstream oss;
    oss.setf(ios::fixed);
    oss << setprecision(10) << x;
    string s = oss.str();
    while (!s.empty() && s.find('.') != string::npos && s.back() == '0') s.pop_back();
    if (!s.empty() && s.back() == '.') s.pop_back();
    if (s == "-0") s = "0";
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Complexo z1, z2;
    if (!(cin >> z1.a >> z1.b)) return 0;
    cin >> z2.a >> z2.b;

    Complexo s = soma(z1, z2);
    Complexo m = mult(z1, z2);

    cout << "Soma: " << formatReal(s.a) << "+" << formatReal(s.b) << "i\n";
    cout << "Multi: " << formatReal(m.a) << "+" << formatReal(m.b) << "i\n";
    return 0;
}