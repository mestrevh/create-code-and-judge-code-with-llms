/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x1, y1, x2, y2;
    double e;
    if (!(cin >> x1 >> y1 >> x2 >> y2)) return 0;
    if (!(cin >> e)) return 0;

    bool focosEmX = (y1 == 0 && y2 == 0 && x1 != x2);
    bool focosEmY = (x1 == 0 && x2 == 0 && y1 != y2);

    double c = 0;
    if (focosEmX) c = fabs((double)x1);
    else c = fabs((double)y1);

    double a2 = (c * c) / (e * e);
    double b2 = a2 * (1.0 - e * e);

    auto formatFloat2 = [](double v) {
        long double lv = (long double)v;
        long double r = llround(lv);
        if (fabsl(lv - r) < 1e-9L) return to_string((long long)r);
        ostringstream oss;
        oss.setf(std::ios::fixed);
        oss << setprecision(12) << (double)v;
        string s = oss.str();
        while (!s.empty() && s.back() == '0') s.pop_back();
        if (!s.empty() && s.back() == '.') s.pop_back();
        if (s.empty()) s = "0";
        return s;
    };

    cout << (focosEmY ? "FOCOS EM Y" : "FOCOS EM X") << "\n";

    if (focosEmX) {
        cout << "x^2/" << formatFloat2(a2) << " + y^2/" << formatFloat2(b2) << " = 1\n";
    } else {
        cout << "x^2/" << formatFloat2(b2) << " + y^2/" << formatFloat2(a2) << " = 1\n";
    }

    return 0;
}