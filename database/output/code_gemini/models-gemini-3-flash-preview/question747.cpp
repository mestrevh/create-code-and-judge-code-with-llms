/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        string s;
        if (!(cin >> s)) break;

        if (!s.empty()) {
            char last_char = s[0];
            cout << last_char;
            for (size_t i = 1; i < s.length(); ++i) {
                if (s[i] != last_char) {
                    last_char = s[i];
                    cout << last_char;
                }
            }
        }
        cout << "\n";
    }

    return 0;
}