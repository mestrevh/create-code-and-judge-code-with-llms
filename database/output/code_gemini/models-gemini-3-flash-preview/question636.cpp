/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double X, Y, Z;
    while (cin >> X >> Y >> Z && (X != 0 || Y != 0 || Z != 0)) {
        long long P, M, G;
        cin >> P >> M >> G;

        long long x = (long long)round(X * 100.0);
        long long y = (long long)round(Y * 100.0);
        long long z = (long long)round(Z * 100.0);

        long long total_n30 = 0;
        long long total_n15_only = 0;
        long long total_n5_only = 0;

        long long dims[5][2] = {
            {x, y}, // Bottom
            {x, z}, // Side 1
            {x, z}, // Side 2
            {y, z}, // Side 3
            {y, z}  // Side 4
        };

        for (int i = 0; i < 5; ++i) {
            long long W = dims[i][0];
            long long H = dims[i][1];
            
            // Maximum potential slots for each tile size in this rectangle
            long long n30 = (W / 30) * (H / 30);
            long long n15_total = (W / 15) * (H / 15);
            long long n5_total = (W / 5) * (H / 5);
            
            total_n30 += n30;
            total_n15_only += (n15_total - 4 * n30);
            total_n5_only += (n5_total - 9 * n15_total);
        }

        // To minimize cost, greedily use the largest (most cost-efficient) tiles
        long long g_used = min(G, total_n30);
        long long n30_leftover_to_be_M = total_n30 - g_used;

        long long total_n15_available_slots = total_n15_only + 4 * n30_leftover_to_be_M;
        long long m_used = min(M, total_n15_available_slots);
        long long n15_leftover_to_be_P = total_n15_available_slots - m_used;

        long long total_n5_needed = total_n5_only + 9 * n15_leftover_to_be_P;

        if (P >= total_n5_needed) {
            cout << total_n5_needed << " " << m_used << " " << g_used << "\n";
        } else {
            cout << "impossivel\n";
        }
    }

    return 0;
}