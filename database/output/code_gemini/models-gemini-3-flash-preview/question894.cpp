/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

/**
 * Problema: Cara ou Coroa
 * Objetivo: Contar combinações de N moedas onde |Heads - Tails| == D
 * Complexidade: O(2^N), onde N <= 15. 2^15 = 32.768, perfeitamente viável em 1s.
 */

long long count_combinations(int index, int current_heads, int n, int d) {
    if (index == n) {
        int current_tails = n - current_heads;
        if (abs(current_heads - current_tails) == d) {
            return 1;
        }
        return 0;
    }
    
    // Tenta colocar Cara (C)
    long long res = count_combinations(index + 1, current_heads + 1, n, d);
    // Tenta colocar Coroa (K)
    res += count_combinations(index + 1, current_heads, n, d);
    
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, D;
    if (cin >> N >> D) {
        cout << count_combinations(0, 0, N, D) << endl;
    }

    return 0;
}

