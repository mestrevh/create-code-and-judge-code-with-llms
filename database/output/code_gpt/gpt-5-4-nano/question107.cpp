/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (cin >> s) {
        bool allZero = true;
        for (char c : s) if (c != '0') { allZero = false; break; }
        if (allZero) break;

        int i = (int)s.size() - 1;
        while (i >= 0) {
            if (s[i] != '0') break;
            i--;
        }
        if (i < 0) i = 0;

        for (; i >= 0; i--) {
            char c = s[i];
            if (c == '0') {
                continue;
            }
            break;
        }

        bool started = false;
        for (int j = (int)s.size() - 1; j >= 0; j--) {
            if (!started) {
                if (s[j] == '0') continue;
                started = true;
            }
            cout << '[' << s[j] << ']';
        }
        if (!started) cout << "[0]";
        cout << "\n";
    }
    return 0;
}