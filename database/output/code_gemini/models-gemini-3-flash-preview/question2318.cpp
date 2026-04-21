/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Funcao recursiva para calcular o n-esimo numero da sequencia de Fibonacci.
 * Utiliza memoizacao para garantir complexidade O(N) e evitar redundancia.
 * Retorna double para evitar overflow de inteiros e permitir comparacao com o nivel de vergonha.
 */
double fib(int n) {
    if (n <= 0) return 0.0;
    if (n == 1) return 1.0;
    
    static double memo[10001];
    static bool visited[10001] = {false};
    
    if (n < 10001 && visited[n]) return memo[n];
    
    double res = fib(n - 1) + fib(n - 2);
    
    if (n < 10001) {
        memo[n] = res;
        visited[n] = true;
    }
    return res;
}

int main() {
    // Otimizacao de Entrada e Saida
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double x, z;
    int y, k;

    // Leitura dos dados de Troy (X e Y) e Gabriella (Z e K)
    if (cin >> x >> y >> z >> k) {
        
        // Processamento de Troy Bolton
        double resultTroy = fib(y);
        if (x > resultTroy) {
            cout << "Nao foi dessa vez!! Troy nao teve coragem o suficiente." << "\n";
        } else {
            cout << "Esse pode ser o comeco de algo novo!! Troy vai cantar!!" << "\n";
        }

        // Processamento de Gabriella Montez
        double resultGabriella = fib(k);
        if (z > resultGabriella) {
            cout << "Nao foi dessa vez!! Gabriella nao teve coragem o suficiente." << "\n";
        } else {
            cout << "Esse pode ser o comeco de algo novo!! Gabriella vai cantar!!" << "\n";
        }
    }

    return 0;
}