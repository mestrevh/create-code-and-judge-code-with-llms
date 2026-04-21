/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c;
    if (!(cin >> a)) return 0;
    cin >> b >> c;

    const double rate = 5.08;

    cout.setf(ios::fixed);
    cout << setprecision(10);

    double r1 = a * rate;
    double r2 = b * rate;
    double r3 = c * rate;

    auto printNum = [&](double x) {
        string s = to_string(x);
        while (!s.empty() && s.back() == '0') s.pop_back();
        if (!s.empty() && s.back() == '.') s.pop_back();
        cout << s;
    };

    printNum(r1);
    cout << "\n";
    printNum(r2);
    cout << "\n";
    printNum(r3);

    return 0;
}