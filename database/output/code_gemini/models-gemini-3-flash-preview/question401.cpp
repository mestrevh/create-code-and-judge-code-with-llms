/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Função que calcula a soma dos dígitos de um número inteiro.
 * Utiliza o operador de módulo para extrair o último dígito e 
 * divisão inteira para remover o último dígito processado.
 */
long long SomaDigitos(long long n) {
    if (n < 0) n = -n;
    long long soma = 0;
    while (n > 0) {
        soma += (n % 10);
        n /= 10;
    }
    return soma;
}

int main() {
    // Otimização de I/O padrão para Programação Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    // Leitura do número inteiro conforme o formato de entrada
    if (cin >> n) {
        cout << SomaDigitos(n) << "\n";
    }

    return 0;
}