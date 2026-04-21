/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problem: Piui-Piui
 * Persona: Competitive Programming Grandmaster
 * Logic: Binary search with specific character-by-character comparison rules.
 * Complexity: O(M * L * log N) where L is max word length (10).
 */

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    // Reading the dictionary of words (W)
    vector<string> words(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }

    // Processing each search query (Q)
    for (int j = 0; j < M; ++j) {
        string query;
        cin >> query;

        int total_comps = 0;
        int left = 0, right = N - 1;
        bool found = false;

        while (left <= right) {
            int mid = (left + right) / 2;
            const string& word = words[mid];

            int res = 0;
            int lenQ = query.length();
            int lenW = word.length();
            int minLen = (lenQ < lenW) ? lenQ : lenW;

            bool diffFound = false;
            // The comparison must be done letter by letter from left to right.
            // It stops at the first difference OR at the end of one (or both) words.
            for (int i = 0; i < minLen; ++i) {
                total_comps++;
                if (query[i] < word[i]) {
                    res = -1;
                    diffFound = true;
                    break;
                }
                if (query[i] > word[i]) {
                    res = 1;
                    diffFound = true;
                    break;
                }
            }

            // If no character difference was found within the minLen,
            // the lexicographical order is determined by the length.
            if (!diffFound) {
                if (lenQ < lenW) res = -1;
                else if (lenQ > lenW) res = 1;
                else res = 0;
            }

            if (res == 0) {
                found = true;
                break;
            } else if (res < 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // Output formatting: SIM/NAO followed by comparison count
        cout << (found ? "SIM " : "NAO ") << total_comps;
        if (j < M - 1) cout << " ";
    }
    cout << endl;

    return 0;
}