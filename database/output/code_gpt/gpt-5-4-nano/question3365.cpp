/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string D, S;
    if (!(cin >> D >> S)) return 0;

    int n = (int)min(D.size(), S.size());
    string mappedS = S;
    vector<char> numToChar(10, 0);
    for (int i = 0; i < n; i++) {
        int digit = D[i] - '0';
        if (0 <= digit && digit <= 9) numToChar[digit] = S[i];
    }

    int N;
    cin >> N;
    while (N--) {
        string t;
        cin >> t;
        string out;
        out.reserve(t.size());
        for (char c : t) {
            if (isdigit((unsigned char)c)) {
                int digit = c - '0';
                char repl = (digit >= 0 && digit <= 9) ? numToChar[digit] : c;
                out.push_back(repl ? repl : c);
            } else {
                out.push_back(c);
            }
        }
        cout << out << "\n";
    }
    return 0;
}