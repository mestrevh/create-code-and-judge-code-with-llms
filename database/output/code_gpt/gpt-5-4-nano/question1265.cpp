/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

const double PI = 3.14;

double areaQuadrado(double lado) {
    if (lado < 0) return -1;
    return lado * lado;
}
double areaRetangulo(double base, double altura) {
    if (base < 0 || altura < 0) return -1;
    return base * altura;
}
double areaCirculo(double raio) {
    if (raio < 0) return -1;
    return PI * raio * raio;
}

double perimetroQuadrado(double lado) {
    if (lado < 0) return -1;
    return 4 * lado;
}
double perimetroRetangulo(double base, double altura) {
    if (base < 0 || altura < 0) return -1;
    return 2 * (base + altura);
}
double perimetroCirculo(double raio) {
    if (raio < 0) return -1;
    return 2 * PI * raio;
}

double metrosTotais(double area, double perimetro) {
    if (area < 0 || perimetro < 0) return -1;
    return area + perimetro;
}

void imprimirResumo(double maiorCirculo, double maiorRetangulo, double maiorQuadrado, int total, int qtdCirculo) {
    cout.setf(std::ios::fixed);
    cout << setprecision(2);
    cout << "Maior circulo: " << maiorCirculo << "\n";
    cout << "Maior retangulo: " << maiorRetangulo << "\n";
    cout << "Maior quadrado: " << maiorQuadrado << "\n";
    cout << "Quantidade de figuras " << total << "\n";
    double perc = total == 0 ? 0.0 : (100.0 * qtdCirculo / total);
    cout << "Percentual de circulos: " << perc << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char tipo;
    int total = 0;
    int qtdCirculo = 0;

    double maiorCirculo = -1;
    double maiorRetangulo = -1;
    double maiorQuadrado = -1;

    while (cin >> tipo) {
        if (tipo == 'sair') break;

        if (tipo == 'q') {
            double lado;
            cin >> lado;
            double a = areaQuadrado(lado);
            double p = perimetroQuadrado(lado);
            double valor = metrosTotais(a, p);
            total++;
            if (valor >= 0) maiorQuadrado = max(maiorQuadrado, valor);
        } else if (tipo == 'r') {
            double base, altura;
            cin >> base >> altura;
            double a = areaRetangulo(base, altura);
            double p = perimetroRetangulo(base, altura);
            double valor = metrosTotais(a, p);
            total++;
            if (valor >= 0) maiorRetangulo = max(maiorRetangulo, valor);
        } else if (tipo == 'c') {
            double raio;
            cin >> raio;
            double a = areaCirculo(raio);
            double p = perimetroCirculo(raio);
            double valor = metrosTotais(a, p);
            total++;
            qtdCirculo++;
            if (valor >= 0) maiorCirculo = max(maiorCirculo, valor);
        }
    }

    if (maiorCirculo < 0) maiorCirculo = 0;
    if (maiorRetangulo < 0) maiorRetangulo = 0;
    if (maiorQuadrado < 0) maiorQuadrado = 0;

    imprimirResumo(maiorCirculo, maiorRetangulo, maiorQuadrado, total, qtdCirculo);
    return 0;
}