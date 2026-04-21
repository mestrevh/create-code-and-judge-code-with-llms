/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Função que exibe os n primeiros elementos da Sequência de Fibonacci.
 * Utiliza o tipo unsigned long long para suportar uma maior gama de valores de n,
 * considerando o crescimento exponencial da sequência.
 */
void exibirFibonacci(int n) {
    if (n <= 0) return;

    unsigned long long a = 1;
    unsigned long long b = 1;

    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            cout << a << "\n";
        } else if (i == 2) {
            cout << b << "\n";
        } else {
            unsigned long long proximo = a + b;
            cout << proximo << "\n";
            a = b;
            b = proximo;
        }
    }
}

int main() {
    // Otimização de I/O para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        exibirFibonacci(n);
    }

    return 0;
}