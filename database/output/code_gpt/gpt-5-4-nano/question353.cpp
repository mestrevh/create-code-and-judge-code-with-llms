/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double P, A;
    if (!(cin >> P >> A)) return 0;

    double imc = P / A / A;

    string ans;
    if (imc < 17.0) ans = "muito abaixo do peso";
    else if (imc < 18.5) ans = "abaixo do peso";
    else if (imc < 25.0) ans = "peso normal";
    else if (imc < 30.0) ans = "acima do peso";
    else if (imc < 35.0) ans = "obesidade";
    else if (imc < 40.0) ans = "obesidade severa";
    else ans = "obesidade morbida";

    cout << ans;
    return 0;
}