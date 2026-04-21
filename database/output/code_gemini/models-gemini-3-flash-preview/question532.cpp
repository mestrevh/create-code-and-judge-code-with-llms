/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Custom comparison function to count the number of character comparisons
 * made during the comparison of two strings.
 * 
 * @param w The word from the search vector.
 * @param q The query word.
 * @param count Reference to the integer tracking character comparisons.
 * @return -1 if w < q, 1 if w > q, 0 if w == q.
 */
int compareWithCount(const string& w, const string& q, int& count) {
    int n1 = (int)w.length();
    int n2 = (int)q.length();
    int minLen = (n1 < n2) ? n1 : n2;
    
    int i = 0;
    while (i < minLen) {
        count++;
        if (w[i] < q[i]) return -1;
        if (w[i] > q[i]) return 1;
        i++;
    }
    
    // If one is a prefix of the other, compare lengths.
    // No further character comparisons are required.
    if (n1 < n2) return -1;
    if (n1 > n2) return 1;
    return 0;
}

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    // Reading the search vector W
    vector<string> W(N);
    for (int i = 0; i < N; ++i) {
        cin >> W[i];
    }

    // Processing each query Q
    for (int j = 0; j < M; ++j) {
        string Q;
        if (!(cin >> Q)) break;

        int count = 0;
        bool found = false;
        int l = 0, r = N - 1;

        // Binary search implementation
        // Calculated m = (l + r) / 2 as per problem instructions
        while (l <= r) {
            int m = (l + r) / 2;
            int res = compareWithCount(W[m], Q, count);
            
            if (res == 0) {
                found = true;
                break;
            } else if (res < 0) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        // Output formatting: SIM/NAO followed by total character comparisons
        if (found) {
            cout << "SIM " << count << "\n";
        } else {
            cout << "NAO " << count << "\n";
        }
    }

    return 0;
}