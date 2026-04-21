/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C;
    if (!(cin >> C)) return 0;

    string line;
    getline(cin, line);

    while (getline(cin, line)) {
        if (line == "FIM") break;

        string decoded = "";
        int letter_pos = 1;
        
        for (int i = 0; i < (int)line.length(); ++i) {
            char c = line[i];
            int alpha_idx = -1;

            if (c >= 'A' && c <= 'Z') {
                alpha_idx = c - 'A';
            } else if (c >= 'a' && c <= 'z') {
                alpha_idx = c - 'a' + 26;
            }

            if (alpha_idx != -1) {
                int p = (alpha_idx - (C + letter_pos)) % 52;
                if (p < 0) p += 52;

                if (p < 26) {
                    decoded += (char)('A' + p);
                } else {
                    decoded += (char)('a' + (p - 26));
                }
                letter_pos++;
            } else {
                decoded += c;
            }
        }
        cout << decoded << "\n";
    }

    return 0;
}