/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    double compra;
    cout << "Digite o valor de compra do produto:\n";
    if (!(cin >> compra)) return 0;

    double venda = (compra < 20.0) ? compra * 1.45 : compra * 1.30;
    cout << "O produto deve ser vendido a R$ ";

    cout.setf(ios::fixed);
    cout << setprecision(10) << venda;

    string s;
    {
        ostringstream oss;
        oss.setf(ios::fixed);
        oss << setprecision(10) << venda;
        s = oss.str();
    }
    while (!s.empty() && s.back() == '0') s.pop_back();
    if (!s.empty() && s.back() == '.') s.pop_back();
    cout.unsetf(ios::floatfield);
    cout << s;

    return 0;
}