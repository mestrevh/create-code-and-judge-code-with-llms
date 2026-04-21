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

    string s;
    if (!getline(cin, s)) {
        return 0;
    }

    while (!s.empty() && (s.back() == '\r' || s.back() == '\n')) {
        s.pop_back();
    }

    int total_score = 0;
    int n = (int)s.length();

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            bool has_i = false;
            if (i > 0 && s[i - 1] == 'i') {
                has_i = true;
            }
            if (i < n - 1 && s[i + 1] == 'i') {
                has_i = true;
            }

            if (has_i) {
                total_score += 2;
            } else {
                total_score += 1;
            }
        }
    }

    cout << total_score << endl;

    return 0;
}