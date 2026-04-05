/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char tipo;
    if (!(cin >> tipo)) return 0;

    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    const double pi = 3.14;

    if (tipo == 'Q') {
        double lado;
        cin >> lado;
        double area = lado * lado;
        double perimetro = 4.0 * lado;
        cout << area << "\n" << perimetro;
    } else if (tipo == 'R') {
        double altura, largura;
        cin >> largura >> altura;
        double area = largura * altura;
        double perimetro = 2.0 * (largura + altura);
        cout << area << "\n" << perimetro;
    } else if (tipo == 'C') {
        double raio;
        cin >> raio;
        double area = pi * raio * raio;
        double comprimento = 2.0 * pi * raio;
        cout << area << "\n" << comprimento;
    } else {
        cout << "Nenhuma figura selecionada";
    }
    return 0;
}