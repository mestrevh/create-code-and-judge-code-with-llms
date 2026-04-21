/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Funcao para verificar se um numero e primo.
 * Um numero e primo se for maior que 1 e nao possuir divisores alem de 1 e ele mesmo.
 */
bool is_prime(long long n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

/**
 * Funcao principal.
 * A complexidade de tempo e O(N * sqrt(max_val)), onde N e a quantidade de numeros
 * e max_val e o maior valor sorteado.
 */
int main() {
    // Otimizacao de I/O para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Tenta ler a quantidade N de numeros
    if (!(cin >> n)) return 0;

    long long x = 0;
    for (int i = 0; i < n; ++i) {
        long long val;
        if (!(cin >> val)) break;

        // Regra: se o numero for um primo impar (val > 2 e primo), subtrair.
        // Caso contrario, somar.
        if (val > 2 && is_prime(val)) {
            x -= val;
        } else {
            x += val;
        }
    }

    // Verificacao do resultado final para determinar a saida
    if (x < 0) {
        cout << "Foi de base" << endl;
    } else {
        cout << "Ele ainda tem " << x << " dias de vida" << endl;
    }

    return 0;
}