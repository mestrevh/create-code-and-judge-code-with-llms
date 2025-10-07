/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

const double PI = 3.14;

double area_quadrado(double lado) {
    if (lado < 0) {
        return -1.0;
    }
    return lado * lado;
}

double area_retangulo(double base, double altura) {
    if (base < 0 || altura < 0) {
        return -1.0;
    }
    return base * altura;
}

double area_circulo(double raio) {
    if (raio < 0) {
        return -1.0;
    }
    return PI * raio * raio;
}

void imprimir_resumo(double max_c, double max_r, double max_q, int total_figuras, int total_circulos) {
    std::cout << "Maior circulo: " << max_c << std::endl;
    std::cout << "Maior retangulo: " << max_r << std::endl;
    std::cout << "Maior quadrado: " << max_q << std::endl;
    std::cout << "Quantidade de figuras " << total_figuras << std::endl;

    double percentual = 0.0;
    if (total_figuras > 0) {
        percentual = (static_cast<double>(total_circulos) / total_figuras) * 100.0;
    }
    std::cout << "Percentual de circulos: " << percentual << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << std::fixed << std::setprecision(2);

    double max_area_c = -1.0;
    double max_area_r = -1.0;
    double max_area_q = -1.0;
    int total_figuras = 0;
    int total_circulos = 0;

    std::string tipo_figura;

    while (std::cin >> tipo_figura && tipo_figura != "sair") {
        total_figuras++;
        char tipo = tipo_figura[0];

        if (tipo == 'q') {
            double lado;
            std::cin >> lado;
            double area = area_quadrado(lado);
            max_area_q = std::max(max_area_q, area);
        } else if (tipo == 'r') {
            double base, altura;
            std::cin >> base >> altura;
            double area = area_retangulo(base, altura);
            max_area_r = std::max(max_area_r, area);
        } else if (tipo == 'c') {
            total_circulos++;
            double raio;
            std::cin >> raio;
            double area = area_circulo(raio);
            max_area_c = std::max(max_area_c, area);
        }
    }

    imprimir_resumo(max_area_c, max_area_r, max_area_q, total_figuras, total_circulos);

    return 0;
}
