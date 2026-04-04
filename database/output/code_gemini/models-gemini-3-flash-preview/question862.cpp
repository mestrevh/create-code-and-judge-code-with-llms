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

    string s;
    while (cin >> s && s != "0") {
        int max_len = 0;
        int max_start = -1;
        int current_len = 0;
        int current_start = -1;

        for (int i = 0; i < (int)s.length(); ++i) {
            if (s[i] == '0') {
                if (current_len == 0) {
                    current_start = i;
                }
                current_len++;
                if (current_len > max_len) {
                    max_len = current_len;
                    max_start = current_start;
                }
            } else {
                current_len = 0;
            }
        }

        if (max_start != -1) {
            cout << max_start << " " << (max_start + max_len - 1) << "\n";
        }
    }

    return 0;
}