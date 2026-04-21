/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double x;
    if (!(cin >> x)) return 0;

    int s = 0;
    if (x < 0) s = -1;
    else if (x > 0) s = 1;
    else s = 0;

    ostringstream oss;
    oss.setf(ios::fmtflags(0), ios::floatfield);
    oss << scientific << setprecision(4) << x;
    string xs = oss.str();

    if (s == 1) {
        cout << "sinal(" << xs << ") = +1";
    } else if (s == -1) {
        cout << "sinal(" << xs << ") = -1";
    } else {
        cout << "sinal(" << xs << ") = 0";
    }
    return 0;
}