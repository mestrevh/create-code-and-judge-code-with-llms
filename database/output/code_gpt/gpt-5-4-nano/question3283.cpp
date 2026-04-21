/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X, Y, Z;
    if (!(cin >> X)) return 0;
    cin >> Y >> Z;

    double areaTri = (double)X * (double)Y / 2.0;
    const double PI = 3.14159;
    double areaCircle = PI * (double)Z * (double)Z;
    double areaTrap = ((double)X + (double)Y) * (double)Y / 2.0;

    cout << fixed << setprecision(2) << areaTri << "\n"
         << fixed << setprecision(2) << areaCircle << "\n"
         << fixed << setprecision(2) << areaTrap << "\n";
    return 0;
}