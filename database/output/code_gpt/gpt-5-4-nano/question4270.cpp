/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    double x;
    if (!(cin >> str >> x)) return 0;

    cout << fixed << setprecision(1);

    if (str == "C" || str == "c" || str == "Celsius" || str == "celsius") {
        double F = x * 1.8 + 32.0;
        double K = x + 273.15;
        cout << F << " F\n" << K << " K\n";
    } else if (str == "K" || str == "k" || str == "Kelvin" || str == "kelvin") {
        double C = x - 273.15;
        double F = C * 1.8 + 32.0;
        cout << C << " C\n" << F << " F\n";
    } else if (str == "F" || str == "f" || str == "Fahrenheit" || str == "fahrenheit") {
        double C = (x - 32.0) / 1.8;
        double K = C + 273.15;
        cout << C << " C\n" << K << " K\n";
    }

    return 0;
}