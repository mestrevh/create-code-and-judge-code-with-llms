/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/**
 * Função para calcular a área do quadrado.
 * Retorna -1 se a dimensão for negativa.
 */
double calcularAreaQuadrado(double lado) {
    if (lado < 0) return -1.0;
    return lado * lado;
}

/**
 * Função para calcular a área do retângulo.
 * Retorna -1 se qualquer dimensão for negativa.
 */
double calcularAreaRetangulo(double base, double altura) {
    if (base < 0 || altura < 0) return -1.0;
    return base * altura;
}

/**
 * Função para calcular a área do círculo.
 * Usa pi = 3.14 conforme solicitado.
 * Retorna -1 se o raio for negativo.
 */
double calcularAreaCirculo(double raio) {
    if (raio < 0) return -1.0;
    return 3.14 * raio * raio;
}

/**
 * Função para imprimir o resumo final com os resultados formatados.
 */
void imprimirResumo(double maxC, double maxR, double maxQ, int total, double percC) {
    cout << fixed << setprecision(2);
    cout << "Maior circulo: " << maxC << "\n";
    cout << "Maior retangulo: " << maxR << "\n";
    cout << "Maior quadrado: " << maxQ << "\n";
    cout << "Quantidade de figuras " << total << "\n";
    cout << "Percentual de circulos: " << percC << "\n";
}

int main() {
    // Otimização de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string tipo;
    double maxC = 0.0, maxR = 0.0, maxQ = 0.0;
    bool hasC = false, hasR = false, hasQ = false;
    int totalFiguras = 0, contadorCirculos = 0;

    // Loop de leitura até encontrar o comando "sair"
    while (cin >> tipo && tipo != "sair") {
        if (tipo == "q") {
            double lado;
            if (!(cin >> lado)) break;
            double area = calcularAreaQuadrado(lado);
            // Atualiza o maior valor. O primeiro valor lido (mesmo que -1) torna-se o max atual.
            if (!hasQ || area > maxQ) {
                maxQ = area;
            }
            hasQ = true;
            totalFiguras++;
        } else if (tipo == "r") {
            double base, altura;
            if (!(cin >> base >> altura)) break;
            double area = calcularAreaRetangulo(base, altura);
            if (!hasR || area > maxR) {
                maxR = area;
            }
            hasR = true;
            totalFiguras++;
        } else if (tipo == "c") {
            double raio;
            if (!(cin >> raio)) break;
            double area = calcularAreaCirculo(raio);
            if (!hasC || area > maxC) {
                maxC = area;
            }
            hasC = true;
            totalFiguras++;
            contadorCirculos++;
        }
    }

    // Cálculo do percentual de círculos
    double percentualCirculos = 0.0;
    if (totalFiguras > 0) {
        percentualCirculos = (double)contadorCirculos * 100.0 / totalFiguras;
    }

    // Chamada da função de saída
    imprimirResumo(maxC, maxR, maxQ, totalFiguras, percentualCirculos);

    return 0;
}