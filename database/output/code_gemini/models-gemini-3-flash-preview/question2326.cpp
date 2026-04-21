/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Função que calcula quantas vezes é possível subtrair Y de X.
 * Em termos matemáticos para números naturais, isso equivale à divisão inteira X / Y.
 */
long long calcularSubtracoes(long long x, long long y) {
    if (y <= 0) return 0;
    return x / y;
}

int main() {
    // Otimização de I/O padrão para programação competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x, y;
    
    // Leitura dos valores de entrada conforme o formato especificado
    if (cin >> x >> y) {
        // Chamada da função e impressão do resultado
        cout << calcularSubtracoes(x, y) << "\n";
    }

    return 0;
}