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

    int P, C;
    if (!(cin >> P >> C)) return 0;

    vector<string> words(P);
    for (int i = 0; i < P; ++i) {
        cin >> words[i];
    }

    int current_idx = 0;
    while (current_idx < P) {
        int line_words_count = 0;
        int line_words_total_chars = 0;
        int temp_idx = current_idx;

        while (temp_idx < P) {
            int word_len = (int)words[temp_idx].length();
            int needed = (line_words_count == 0) ? word_len : (1 + word_len);
            
            if (line_words_total_chars + line_words_count + word_len <= C) {
                line_words_total_chars += word_len;
                line_words_count++;
                temp_idx++;
            } else {
                break;
            }
        }

        if (temp_idx == P) {
            for (int i = 0; i < line_words_count; ++i) {
                cout << words[current_idx + i];
                if (i < line_words_count - 1) cout << ' ';
            }
            cout << '\n';
        } else {
            int S = C - line_words_total_chars;
            int G = line_words_count - 1;

            if (G > 0) {
                int base_space = S / G;
                int extra_space = S % G;

                for (int i = 0; i < line_words_count; ++i) {
                    cout << words[current_idx + i];
                    if (i < G) {
                        int count = base_space + (i < extra_space ? 1 : 0);
                        for (int j = 0; j < count; ++j) cout << ' ';
                    }
                }
            } else {
                cout << words[current_idx];
                int rem = C - (int)words[current_idx].length();
                for (int j = 0; j < rem; ++j) cout << ' ';
            }
            cout << '\n';
        }
        current_idx = temp_idx;
    }

    return 0;
}

