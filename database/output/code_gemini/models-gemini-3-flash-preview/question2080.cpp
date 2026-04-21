/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

/**
 * Funcao para verificar se um numero e primo.
 * Complexidade de tempo: O(sqrt(N))
 */
bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    // Otimizacao de entrada e saida padrao C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    // Processamento de entrada. Como N pode ser muito grande (ate 2^63-1),
    // ler como string e a forma mais segura e eficiente de processar cada digito.
    while (cin >> s) {
        // h[i] armazena a quantidade de buracos no digito i:
        // 0:1, 1:0, 2:0, 3:0, 4:1, 5:0, 6:1, 7:0, 8:2, 9:1
        int h[] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
        int total_holes = 0;

        for (char c : s) {
            if (c >= '0' && c <= '9') {
                total_holes += h[c - '0'];
            }
        }

        // Verifica se a soma total de buracos e um numero primo
        if (is_prime(total_holes)) {
            cout << "S\n";
        } else {
            cout << "N\n";
        }
    }

    return 0;
}