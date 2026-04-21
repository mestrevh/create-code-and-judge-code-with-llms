/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Pizza do vô Pepe
 * The task is to determine if a pizza of circumference C can be divided into N equal sectors 
 * (each of length L = C/N) such that each sector contains exactly one olive.
 * There are N olives at positions X_i.
 * 
 * Logic:
 * Let each sector start at d, d+L, d+2L, ..., d+(N-1)L.
 * An olive X_i belongs to sector k if d + kL <= X_i < d + (k+1)L (with circular wrap-around).
 * Since olives are sorted, if the division is possible, there must be some olive X_j 
 * that falls into the "first" sector [d, d+L). Then X_{j+1} must be in [d+L, d+2L), 
 * and so on, with wrap-around using X_i + C for the second lap.
 * 
 * This condition is equivalent to: d <= P_{j+k} - kL < d + L for all k from 0 to N-1,
 * where P is the sequence X_0, X_1, ..., X_{N-1}, X_0+C, X_1+C, ...
 * This means for a fixed j, such a d exists if and only if:
 * max_{k=0 to N-1}(P_{j+k} - kL) - min_{k=0 to N-1}(P_{j+k} - kL) < L.
 * 
 * It can be shown that this spread (max - min) is independent of the choice of j.
 * Thus, we only need to check the condition for j=0.
 * Complexidade: O(N) para leitura e cálculo do spread.
 */

int main() {
    // Standard I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long C, N;
    if (!(cin >> C >> N)) return 0;

    // The length of each piece
    long long L = C / N;

    // Positions of the N olives
    vector<long long> X(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }

    // Calculating the spread of Z_i = X_i - i*L
    // If the spread is less than L, then a valid division offset d exists.
    long long min_W, max_W;
    for (int i = 0; i < N; ++i) {
        long long W = X[i] - i * L;
        if (i == 0) {
            min_W = max_W = W;
        } else {
            if (W < min_W) min_W = W;
            if (W > max_W) max_W = W;
        }
    }

    // Output S if the condition is met, N otherwise
    if (max_W - min_W < L) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}