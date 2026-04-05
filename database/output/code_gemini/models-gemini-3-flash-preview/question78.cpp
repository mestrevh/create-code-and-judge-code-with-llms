/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    while (getline(cin, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        if (line == "NAO QUERO MAIS") {
            break;
        }

        int spaces = 0;
        int count_a = 0;
        int freq[26][26] = {0};
        int n = line.length();

        for (int i = 0; i < n; ++i) {
            if (line[i] == ' ') {
                spaces++;
            }

            char c1 = (unsigned char)line[i];
            if (tolower(c1) == 'a') {
                count_a++;
            }

            if (i + 1 < n) {
                char c1_p = (unsigned char)line[i];
                char c2_p = (unsigned char)line[i + 1];

                if (isalpha(c1_p) && isalpha(c2_p)) {
                    int idx1 = tolower(c1_p) - 'a';
                    int idx2 = tolower(c2_p) - 'a';
                    freq[idx1][idx2]++;
                }
            }
        }

        int max_freq = 0;
        int best_i = -1;
        int best_j = -1;

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (freq[i][j] > max_freq) {
                    max_freq = freq[i][j];
                    best_i = i;
                    best_j = j;
                }
            }
        }

        cout << spaces << "\n";
        cout << count_a << "\n";

        if (max_freq == 0) {
            cout << "NENHUM PAR\n";
        } else {
            cout << max_freq << "\n";
            char p1 = (char)(best_i + 'a');
            char p2 = (char)(best_j + 'a');
            cout << p1 << p2 << "\n";
        }
    }

    return 0;
}