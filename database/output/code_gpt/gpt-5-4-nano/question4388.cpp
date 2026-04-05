/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    int bad = 0;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        bool ok = true;
        if (s.size() != 7) ok = false;

        for (int j = 0; ok && j < 7; j++) {
            char c = s[j];
            bool isLetter = (c >= 'A' && c <= 'Z');
            bool isDigit = (c >= '0' && c <= '9');

            if (j == 0 || j == 1 || j == 2 || j == 4) {
                if (!isLetter) ok = false;
            } else {
                if (!isDigit) ok = false;
            }
        }
        if (!ok) bad++;
    }

    cout << bad << "\n";
    return 0;
}