/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
 * Funcao recursiva para calcular a potencia x^n.
 * x: base double
 * n: expoente inteiro
 */
double recursivePower(double x, int n) {
    if (n <= 0) return 1.0;
    return x * recursivePower(x, n - 1);
}

/**
 * Funcao recursiva para calcular o fatorial de n.
 * Retorna double para evitar overflow precoce e facilitar a divisao.
 */
double recursiveFactorial(int n) {
    if (n <= 1) return 1.0;
    return (double)n * recursiveFactorial(n - 1);
}

int main() {
    // Otimizacao de I/O para Programacao Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double x;
    if (!(cin >> x)) return 0;

    // Valor "real" da funcao exponencial usando a biblioteca math
    double real_value = exp(x);
    double current_approx = 0.0;
    int i = 0;

    // Loop de expansao da serie de Taylor
    while (true) {
        // Calcula o termo x^i / i! usando as funcoes recursivas
        current_approx += recursivePower(x, i) / recursiveFactorial(i);
        
        // Saida formatada conforme os requisitos: x com 1 casa decimal e aproximacao com 5
        cout << "e^" << fixed << setprecision(1) << x 
             << " com " << i << " iteracoes -> " 
             << fixed << setprecision(5) << current_approx << "\n";
        
        // Condicao de parada: Erro <= 10^-4
        // abs() de <cmath> funciona para double em C++ moderno
        if (abs(real_value - current_approx) <= 0.0001) {
            break;
        }
        i++;
    }

    // Saida final com duas quebras de linha (uma encerra a linha anterior, a outra cria a linha em branco)
    cout << "\n\nNumero de iteracoes -> " << i << endl;

    return 0;
}