/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * Problema: Contar a quantidade de divisores comuns entre A e B.
 * O número de valores possíveis para a pontuação X é o número de divisores do MDC(A, B).
 * Complexidade: O(log(min(A, B)) + sqrt(MDC(A, B)))
 */

long long calculate_gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    if (!(cin >> A >> B)) return 0;

    long long g = calculate_gcd(A, B);
    
    int divisors_count = 0;
    for (long long i = 1; i * i <= g; ++i) {
        if (g % i == 0) {
            divisors_count++;
            if (i * i != g) {
                divisors_count++;
            }
        }
    }

    cout << divisors_count << "\n";

    return 0;
}