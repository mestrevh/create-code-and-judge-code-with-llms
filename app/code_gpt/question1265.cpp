/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double calcularAreaQuadrado(double lado) {
    return lado * lado;
}

double calcularAreaRetangulo(double base, double altura) {
    return base * altura;
}

double calcularAreaCirculo(double raio) {
    return 3.14 * raio * raio;
}

void imprimirResumo(double maiorQuadrado, double maiorRetangulo, double maiorCirculo, int totalFiguras, int totalCirculos) {
    cout << fixed << setprecision(2);
    cout << "Maior circulo: " << maiorCirculo << endl;
    cout << "Maior retangulo: " << maiorRetangulo << endl;
    cout << "Maior quadrado: " << maiorQuadrado << endl;
    cout << "Quantidade de figuras " << totalFiguras << endl;
    cout << "Percentual de circulos: " << (static_cast<double>(totalCirculos) / totalFiguras) * 100 << endl;
}

int main() {
    string tipoFigura;
    double lado, base, altura, raio;
    double maiorQuadrado = -1, maiorRetangulo = -1, maiorCirculo = -1;
    int totalFiguras = 0, totalCirculos = 0;

    while (true) {
        cin >> tipoFigura;
        if (tipoFigura == "sair") break;

        if (tipoFigura == "q") {
            cin >> lado;
            if (lado >= 0) {
                double area = calcularAreaQuadrado(lado);
                maiorQuadrado = max(maiorQuadrado, area);
            }
            totalFiguras++;
        } else if (tipoFigura == "r") {
            cin >> base >> altura;
            if (base >= 0 && altura >= 0) {
                double area = calcularAreaRetangulo(base, altura);
                maiorRetangulo = max(maiorRetangulo, area);
            }
            totalFiguras++;
        } else if (tipoFigura == "c") {
            cin >> raio;
            if (raio >= 0) {
                double area = calcularAreaCirculo(raio);
                maiorCirculo = max(maiorCirculo, area);
                totalCirculos++;
            }
            totalFiguras++;
        }
    }

    if (totalFiguras > 0) {
        imprimirResumo(maiorQuadrado, maiorRetangulo, maiorCirculo, totalFiguras, totalCirculos);
    }

    return 0;
}
