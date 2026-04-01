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

    if (!s.empty() && s.at(s.length() - 1) == '\r') {
        s.erase(s.length() - 1);
    }

    int n;
    if (cin >> n) {
        for (int i = 0; i < n; ++i) {
            int idx;
            char c;
            if (cin >> idx >> c) {
                if (idx >= 0 && (size_t)idx < s.length()) {
                    s.at(idx) = c;
                }
            }
        }
    }

    cout << s << endl;

    return 0;
}