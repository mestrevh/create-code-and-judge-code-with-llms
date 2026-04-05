/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string figura;
    if (!getline(cin, figura)) return 0;
    if (!figura.empty() && figura.back() == '\r') figura.pop_back();

    auto toLower = [](string s) {
        for (char &c : s) c = (char)tolower((unsigned char)c);
        return s;
    };
    figura = toLower(figura);

    double area;
    bool ok = true;

    cout.setf(ios::fixed);
    cout << setprecision(2);

    if (figura == "retangulo" || figura == "retângulo" || figura == "retangulo " ) {
        double base, altura;
        if (!(cin >> base >> altura)) ok = false;
        else area = base * altura;
    } else if (figura == "triangulo" || figura == "triângulo") {
        double base, altura;
        if (!(cin >> base >> altura)) ok = false;
        else area = (base * altura) / 2.0;
    } else if (figura == "trapezio" || figura == "trapézio") {
        double basemaior, basemenor, altura;
        if (!(cin >> basemaior >> basemenor >> altura)) ok = false;
        else area = ((basemaior + basemenor) * altura) / 2.0;
    } else if (figura == "circulo" || figura == "círculo") {
        double raio;
        if (!(cin >> raio)) ok = false;
        else area = 3.1415 * raio * raio;
    } else {
        ok = false;
    }

    if (!ok) {
        cout << "Figura invalida.";
    } else {
        cout << area;
    }

    return 0;
}