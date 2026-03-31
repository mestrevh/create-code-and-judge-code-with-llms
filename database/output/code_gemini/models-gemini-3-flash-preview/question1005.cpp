/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Competitive Programming solution for Bloom Filter false positive detection.
 * Complexity: O((N + Q) * K * L + Q log N)
 * Space: O(N * L + M + K * L)
 */

int main() {
    // Optimize standard C++ I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    // The registered users are already provided in lexicographical order.
    // Storing them in a vector allows O(log N) verification via binary search.
    vector<string> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    int M, K;
    if (!(cin >> M >> K)) return 0;

    // Pre-calculate powers of each base B[k] modulo M to optimize hash computation.
    // powers[k][j] = B[k]^j % M. Max string length L is 100.
    vector<vector<int>> powers(K, vector<int>(101));
    for (int i = 0; i < K; ++i) {
        int base;
        cin >> base;
        long long cur = 1;
        for (int j = 0; j < 100; ++j) {
            powers[i][j] = (int)(cur % M);
            cur = (cur * base) % M;
        }
    }

    // Bloom Filter bit array. Using vector<char> instead of vector<bool> 
    // for slightly faster access in some environments.
    vector<char> V(M, 0);

    // Populate the Bloom Filter for all registered users S[i].
    for (int i = 0; i < N; ++i) {
        const string& s = S[i];
        int len = (int)s.length();
        for (int k = 0; k < K; ++k) {
            long long h = 0;
            const int* p_k = powers[k].data();
            for (int j = 0; j < len; ++j) {
                // ASCII value * base^j mod M
                // Intermediate sum fits in 32-bit signed int for L=100, M=10^5,
                // but long long is used to be safe.
                h += (long long)(unsigned char)s[j] * p_k[j];
            }
            V[(int)(h % M)] = 1;
        }
    }

    int Q;
    if (!(cin >> Q)) return 0;

    string T;
    T.reserve(100);
    while (Q--) {
        if (!(cin >> T)) break;
        int len = (int)T.length();
        bool present_in_filter = true;
        
        // Step 1: Check if the string exists in the Bloom Filter.
        for (int k = 0; k < K; ++k) {
            long long h = 0;
            const int* p_k = powers[k].data();
            for (int j = 0; j < len; ++j) {
                h += (long long)(unsigned char)T[j] * p_k[j];
            }
            if (!V[(int)(h % M)]) {
                present_in_filter = false;
                break;
            }
        }

        if (!present_in_filter) {
            // Case 0: String is definitely not in the registered set.
            cout << "0\n";
        } else {
            // Case 1 or 2: Bloom filter suggests presence. We must check the actual set.
            if (binary_search(S.begin(), S.end(), T)) {
                // Case 2: String is truly in the set.
                cout << "2\n";
            } else {
                // Case 1: Bloom filter false positive.
                cout << "1\n";
            }
        }
    }

    return 0;
}