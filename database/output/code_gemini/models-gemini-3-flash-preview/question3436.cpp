/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
 * Função para calcular a área de um círculo dado o seu raio.
 * Utiliza o valor de PI com a maior precisão possível via acos(-1.0).
 */
double calcularArea(double raio) {
    const double PI = acos(-1.0);
    return PI * raio * raio;
}

/**
 * Função para calcular o perímetro de um círculo dado o seu raio.
 * Utiliza o valor de PI com a maior precisão possível via acos(-1.0).
 */
double calcularPerimetro(double raio) {
    const double PI = acos(-1.0);
    return 2.0 * PI * raio;
}

int main() {
    // Otimização de I/O para Programação Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double raio;
    
    // Leitura do raio conforme o formato de entrada
    if (cin >> raio) {
        // Configuração da saída para 5 casas decimais conforme o formato de saída
        cout << fixed << setprecision(5);
        
        // Chamada das funções e impressão dos resultados em coluna
        cout << calcularArea(raio) << "\n";
        cout << calcularPerimetro(raio) << "\n";
    }

    return 0;
}