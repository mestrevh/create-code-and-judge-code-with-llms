/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Funcao recursiva para calcular o MDC utilizando o Algoritmo de Euclides.
 * Complexidade de Tempo: O(log(min(a, b)))
 * Complexidade de Espaco: O(log(min(a, b))) devido a pilha de recursao.
 */
long long mdc_recursivo(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return mdc_recursivo(b, a % b);
}

int main() {
    // Otimizacao de I/O para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Leitura do numero de casos de teste
    if (!(cin >> n)) {
        return 0;
    }

    while (n--) {
        long long a, b;
        // Leitura dos dois numeros para cada caso
        if (cin >> a >> b) {
            long long resultado = mdc_recursivo(a, b);
            // Saida formatada conforme a especificacao: MDC(a,b) = R
            cout << "MDC(" << a << "," << b << ") = " << resultado << "\n";
        }
    }

    return 0;
}