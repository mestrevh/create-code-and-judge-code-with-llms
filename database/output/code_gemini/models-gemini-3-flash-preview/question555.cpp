/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L;
    if (!(cin >> L)) return 0;

    string s;
    vector<string> words;
    while (cin >> s) {
        words.push_back(s);
    }

    int n = words.size();
    if (n == 0) return 0;

    vector<long long> dp(n + 1, -1);
    vector<int> split(n, 0);

    dp[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        long long current_word_len_sum = 0;
        for (int j = i; j < n; ++j) {
            current_word_len_sum += (long long)words[j].length();
            
            // Check if words i to j can fit in one line with at least one space between them
            // Total length required = sum of word lengths + (number of words - 1)
            if (current_word_len_sum + (j - i) <= (long long)L) {
                // Cost is (L - sum of word lengths)^3
                long long spaces = (long long)L - current_word_len_sum;
                long long cost = spaces * spaces * spaces;
                
                if (dp[j + 1] != -1) {
                    long long total_cost = cost + dp[j + 1];
                    // Minimize cost. In case of tie, we take the one that packs more words (larger j)
                    if (dp[i] == -1 || total_cost <= dp[i]) {
                        dp[i] = total_cost;
                        split[i] = j;
                    }
                }
            } else {
                // If words i to j don't fit, then i to j+1 won't either
                break;
            }
        }
    }

    // Reconstruct and print the lines
    int curr = 0;
    while (curr < n) {
        int next_split = split[curr];
        for (int i = curr; i <= next_split; ++i) {
            cout << words[i] << (i == next_split ? "" : " ");
        }
        cout << "\n";
        curr = next_split + 1;
    }

    return 0;
}