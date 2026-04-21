/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

/**
 * Problema: Figuras (Triângulos Superior, Inferior ou Total)
 * Persona: Grande Mestre em Programação Competitiva
 * Estratégia: 
 * - O triângulo superior (S) tem a base na parte inferior (aponta para cima).
 * - O triângulo inferior (I) tem a base na parte superior (aponta para baixo).
 * - O deslocamento de cada linha segue um padrão de 2 espaços para manter a simetria com "star-space".
 * - O número de estrelas em cada linha segue a progressão aritmética de números ímpares (1, 3, 5...).
 */

int main() {
    // Otimização padrão de I/O para C++ competitivo
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    char k;

    // Leitura dos parâmetros de entrada
    if (!(cin >> n >> k)) {
        return 0;
    }

    // Processamento do Triângulo Superior (S)
    // Também faz parte do Total (T)
    if (k == 'S' || k == 'T') {
        for (int i = 0; i < n; ++i) {
            // Espaçamento inicial para alinhar o triângulo (2 espaços por nível)
            int leading_spaces = 2 * (n - 1 - i);
            for (int j = 0; j < leading_spaces; ++j) {
                cout << ' ';
            }
            // Quantidade de estrelas na linha i: 2*i + 1
            int stars = 2 * i + 1;
            for (int j = 0; j < stars; ++j) {
                cout << '*';
                // Espaço entre estrelas, sem espaço residual no final da linha para evitar PE (Presentation Error)
                if (j < stars - 1) {
                    cout << ' ';
                }
            }
            cout << '\n';
        }
    }

    // Processamento do Triângulo Inferior (I)
    // Também faz parte do Total (T)
    if (k == 'I' || k == 'T') {
        for (int i = 0; i < n; ++i) {
            // Espaçamento inicial para alinhar o triângulo (aumenta 2 espaços por nível)
            int leading_spaces = 2 * i;
            for (int j = 0; j < leading_spaces; ++j) {
                cout << ' ';
            }
            // Quantidade de estrelas na linha i: 2*(n-1-i) + 1
            int stars = 2 * (n - 1 - i) + 1;
            for (int j = 0; j < stars; ++j) {
                cout << '*';
                if (j < stars - 1) {
                    cout << ' ';
                }
            }
            cout << '\n';
        }
    }

    return 0;
}