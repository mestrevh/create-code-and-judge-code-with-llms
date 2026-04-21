/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

string formatNumber(double x) {
    if (fabs(x - llround(x)) < 1e-9) return to_string(llround(x));
    ostringstream oss;
    oss.setf(std::ios::fixed);
    oss << setprecision(10) << x;
    string s = oss.str();
    while (!s.empty() && s.back() == '0') s.pop_back();
    if (!s.empty() && s.back() == '.') s.pop_back();
    if (s.empty() || s == "-0") s = "0";
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b;
    if (!(cin >> a >> b)) return 0;

    const double eps = 1e-9;
    if (fabs(a - b) <= eps) {
        cout << "são iguais";
        return 0;
    }

    double m = (a > b) ? a : b;
    cout << formatNumber(m);
    return 0;
}