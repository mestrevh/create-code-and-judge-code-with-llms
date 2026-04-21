/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Bom Amigo Secreto
 * The problem describes a modified Secret Santa where a draw forms a cycle. 
 * If A draws B, then B draws C, and so on, until someone draws the first person.
 * For each draw A->B, gifts are exchanged both ways: A gives to B, and B gives back to A.
 * We need to count the number of distinct configurations (sets of gift-exchanging pairs)
 * such that the draw forms a single Hamiltonian cycle including all N people.
 * 
 * Logic:
 * - A draw that includes everyone is a single N-cycle permutation.
 * - For N people, there are (N-1)! such permutations (Hamiltonian cycles in a complete graph).
 * - Two configurations are identical if they result in the same set of gift-exchanging pairs.
 * - This corresponds to undirected Hamiltonian cycles.
 * - For N >= 3, each undirected cycle corresponds to two directed cycles.
 *   So the number of configurations is (N-1)! / 2.
 * - For N = 2, there is only one possible draw (A draws B, B draws A), 
 *   which results in one pair {A, B}. Thus, f(2) = 1.
 * 
 * Modular Inverse:
 * - We need (N-1)! / 2 modulo 10^9 + 7.
 * - 10^9 + 7 is prime.
 * - The modular inverse of 2 modulo 10^9 + 7 is 500000004.
 */

int main() {
    // Optimize input and output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const long long MOD = 1000000007LL;
    const long long INV2 = 500000004LL;
    const int MAXN = 1000;

    // Precalculate factorials up to 1000
    vector<long long> fact(MAXN + 1);
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = (fact[i - 1] * (long long)i) % MOD;
    }

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        if (!(cin >> N)) break;

        if (N == 2) {
            // Special case for N=2
            cout << 1 << "\n";
        } else if (N >= 3) {
            // General formula for N >= 3: (N-1)! / 2 mod 10^9 + 7
            long long ans = (fact[N - 1] * INV2) % MOD;
            cout << ans << "\n";
        } else {
            // Based on constraints 2 <= N <= 10^3, this part is not reached.
            cout << 0 << "\n";
        }
    }

    return 0;
}