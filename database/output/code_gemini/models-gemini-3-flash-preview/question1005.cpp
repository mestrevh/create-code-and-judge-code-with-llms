/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> registered(n);
    for (int i = 0; i < n; ++i) {
        cin >> registered[i];
    }

    int m, k;
    if (!(cin >> m >> k)) return 0;

    vector<int> bases(k);
    for (int i = 0; i < k; ++i) {
        cin >> bases[i];
    }

    // Precompute powers of each base B[i]^j mod M for string length up to 100.
    vector<vector<int>> powers(k, vector<int>(101));
    for (int i = 0; i < k; ++i) {
        powers[i][0] = 1 % m;
        for (int j = 1; j <= 100; ++j) {
            powers[i][j] = (int)((1LL * powers[i][j - 1] * bases[i]) % m);
        }
    }

    // Initialize Bloom Filter bitset.
    // Using vector<char> as it is often faster than vector<bool> on many compilers.
    vector<char> filter(m, 0);
    for (int i = 0; i < n; ++i) {
        int len = registered[i].length();
        for (int j = 0; j < k; ++j) {
            long long h = 0;
            for (int l = 0; l < len; ++l) {
                // H[i](S) = (S[0]*B[i]^0 + S[1]*B[i]^1 + ... + S[L-1]*B[i]^(L-1)) mod M
                h += (long long)(unsigned char)registered[i][l] * powers[j][l];
            }
            filter[h % m] = 1;
        }
    }

    int q;
    if (!(cin >> q)) return 0;
    while (q--) {
        string t;
        cin >> t;
        int len = t.length();
        bool bloom_says_yes = true;

        for (int j = 0; j < k; ++j) {
            long long h = 0;
            for (int l = 0; l < len; ++l) {
                h += (long long)(unsigned char)t[l] * powers[j][l];
            }
            if (!filter[h % m]) {
                bloom_says_yes = false;
                break;
            }
        }

        if (!bloom_says_yes) {
            // Not present in Bloom filter.
            cout << "0\n";
        } else {
            // Check if it's a true member or a false positive.
            // Strings are sorted, so we can use binary_search.
            if (binary_search(registered.begin(), registered.end(), t)) {
                // True Positive.
                cout << "2\n";
            } else {
                // False Positive.
                cout << "1\n";
            }
        }
    }

    return 0;
}