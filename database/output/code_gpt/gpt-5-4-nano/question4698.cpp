/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double a, b;
    if (!(cin >> a)) return 0;
    if (!(cin >> b)) return 0;

    long double s = a + b;

    auto isInteger = [](long double x) {
        long double r = llround(x);
        return fabsl(x - r) < 1e-12L;
    };

    auto formatSingleDecimal = [](long double x) {
        ostringstream oss;
        oss.setf(ios::fixed);
        oss << setprecision(1) << (double)x;
        return oss.str();
    };

    auto formatIntegerNoDecimal = [](long double x) {
        long long r = llround(x);
        return to_string(r);
    };

    string sa = formatSingleDecimal(a);
    string sb = formatSingleDecimal(b);

    string ss = isInteger(s) ? formatIntegerNoDecimal(s) : formatSingleDecimal(s);

    cout << "O resultado de " << sa << " + " << sb << " eh " << ss;
    return 0;
}