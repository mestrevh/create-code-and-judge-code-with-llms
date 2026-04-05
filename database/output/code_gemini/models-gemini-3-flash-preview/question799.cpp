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

    int S, L, C;
    while (cin >> S >> L >> C && S != 0) {
        string dummy;
        getline(cin, dummy);

        vector<int> costs;
        costs.reserve(36);
        for (int r = 1; r <= L; ++r) {
            for (int c = 1; c <= C; ++c) {
                costs.push_back(r + c);
            }
        }
        sort(costs.begin(), costs.end());

        for (int i = 0; i < S; ++i) {
            string sentence;
            if (!getline(cin, sentence)) break;

            long long freq[256] = {0};
            for (char ch : sentence) {
                if (ch != ' ') {
                    freq[(unsigned char)ch]++;
                }
            }

            vector<long long> counts;
            counts.reserve(256);
            for (int j = 0; j < 256; ++j) {
                if (freq[j] > 0) {
                    counts.push_back(freq[j]);
                }
            }
            sort(counts.rbegin(), counts.rend());

            long long totalCost = 0;
            for (size_t j = 0; j < counts.size(); ++j) {
                if (j < costs.size()) {
                    totalCost += counts[j] * (long long)costs[j];
                }
            }
            cout << totalCost << "\n";
        }
    }

    return 0;
}