/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    while (cin >> k && k != 0) {
        long long m;
        if (!(cin >> m)) break;

        bool possible = true;
        int n = 0;
        
        // A hypercube must have k = 2^n vertices
        if (k < 1 || (k & (k - 1)) != 0) {
            possible = false;
        } else {
            int temp = k;
            while (temp > 1) {
                temp >>= 1;
                n++;
            }
        }

        // A hypercube must have m = n * 2^(n-1) edges
        if (possible && m != (long long)n * k / 2) {
            possible = false;
        }

        set<pair<long long, long long>> unique_edges;
        for (long long i = 0; i < m; ++i) {
            long long u, v;
            cin >> u >> v;
            if (!possible) continue;

            // Identifiers must be unique and in the range [0, k-1]
            // Also, connected nodes must differ by exactly one bit
            if (u < 0 || u >= k || v < 0 || v >= k) {
                possible = false;
            } else if (__builtin_popcountll(u ^ v) != 1) {
                possible = false;
            } else {
                if (u > v) swap(u, v);
                if (unique_edges.count({u, v})) {
                    // Hypercubes are simple graphs (no duplicate edges)
                    possible = false;
                } else {
                    unique_edges.insert({u, v});
                }
            }
        }

        // Final validation: check if all criteria were met
        if (possible && (long long)unique_edges.size() == m) {
            cout << "SIM" << endl;
        } else {
            cout << "NAO" << endl;
        }
    }

    return 0;
}