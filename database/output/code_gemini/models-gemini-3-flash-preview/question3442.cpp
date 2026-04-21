/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

typedef __int128_t int128;

inline int128 f(long long K, int128 V2, int128 D1) {
    int128 current_D = D1 + (int128)50 * K;
    int128 hits_needed = (V2 + current_D - 1) / current_D;
    return (int128)K + hits_needed;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    while (n--) {
        long long v1_in, v2_in, d1_in, d2_in;
        if (!(cin >> v1_in >> v2_in >> d1_in >> d2_in)) break;

        int128 V1 = (int128)v1_in;
        int128 V2 = (int128)v2_in;
        int128 D1 = (int128)d1_in;
        int128 D2 = (int128)d2_in;

        int128 T_Bezaliel = (V1 + D2 - 1) / D2;

        long long low = 0, high = 2000000000000000000LL; 
        for (int i = 0; i < 105; ++i) {
            long long m1 = low + (high - low) / 3;
            long long m2 = high - (high - low) / 3;
            if (f(m1, V2, D1) < f(m2, V2, D1)) {
                high = m2;
            } else {
                low = m1;
            }
        }

        int128 min_val = f(low, V2, D1);
        long long start_k = (low > 100 ? low - 100 : 0LL);
        long long end_k = low + 100;
        for (long long k = start_k; k <= end_k; ++k) {
            int128 val = f(k, V2, D1);
            if (val < min_val) {
                min_val = val;
            }
        }

        if (min_val <= T_Bezaliel) {
            cout << "Clodes\n";
        } else {
            cout << "Bezaliel\n";
        }
    }

    return 0;
}