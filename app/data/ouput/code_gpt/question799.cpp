/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
    int S, L, C;

    while (cin >> S >> L >> C, S) {
        vector<string> sentences(S);
        unordered_map<char, int> char_position[36];

        for (int i = 0; i < S; ++i) {
            cin.ignore();
            getline(cin, sentences[i]);
            for (char ch : sentences[i]) {
                if (isalpha(ch) || isdigit(ch) || ch == ' ') {
                    char_position[ch].push_back(i);
                }
            }
        }

        vector<int> row_cost(L + 1, 0);
        vector<int> col_cost(C + 1, 0);

        for (int i = 1; i <= L; ++i) {
            for (int j = 1; j <= C; ++j) {
                row_cost[i] += i;
                col_cost[j] += j;
            }
        }

        int min_cost = INT_MAX;

        do {
            int current_cost = 0;
            for (const auto& sentence : sentences) {
                for (char ch : sentence) {
                    if (ch == ' ') continue;
                    current_cost += row_cost[char_position[ch][0]] + col_cost[char_position[ch][1]];
                }
            }
            min_cost = min(min_cost, current_cost);
        } while (next_permutation(char_position, char_position + 36));

        cout << min_cost << endl;
    }

    return 0;
}
