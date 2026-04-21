/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c, d;
    if (!(cin >> a)) return 0;
    cin >> b >> c >> d;

    const double PI = acos(-1.0);
    const double e = exp(1.0);

    vector<double> vals(8);

    auto r4 = [](double x) { return round(x * 10000.0) / 10000.0; };

    vals[0] = r4((a + b) * c / d);
    vals[1] = r4(log(a + b) + c * d);
    vals[2] = r4(log10(fabs(a)) + log10(fabs(b)) - log10(fabs(c)));
    vals[3] = r4((log(fabs(a)) / log(10.0)) + (log(fabs(b)) / log(10.0)) * (c / d));
    vals[4] = r4((a * c - b * d) / (a - b));
    vals[5] = r4(pow(a + b, 2.0) / (c + d));
    vals[6] = r4((log(e) + log10(PI)) * (a / (b + c)));
    vals[7] = r4((a + b + c + d) * (log(fabs(a * b * c * d))));

    cout.setf(std::ios::fixed);
    cout << setprecision(4);

    for (int i = 0; i < 8; i++) {
        if (i == 0) cout << "i) " << r4(vals[i]) << "\n";
        else if (i == 1) cout << "ii) " << r4(vals[i]) << "\n";
        else if (i == 2) cout << "iii) " << r4(vals[i]) << "\n";
        else if (i == 3) cout << "iv) " << r4(vals[i]) << "\n";
        else if (i == 4) cout << "v) " << r4(vals[i]) << "\n";
        else if (i == 5) cout << "vi) " << r4(vals[i]) << "\n";
        else if (i == 6) cout << "vii) " << r4(vals[i]) << "\n";
        else cout << "viii) " << r4(vals[i]) << "\n";
    }

    return 0;
}