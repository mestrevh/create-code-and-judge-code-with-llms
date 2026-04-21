/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long C;
    if (!(cin >> C)) return 0;

    string s;
    const int N = 52;
    while (cin >> ws && getline(cin, s)) {
        if (s == "FIM") break;

        int shift = (int)(C % N);
        for (char &ch : s) {
            if ('A' <= ch && ch <= 'Z') {
                int p = ch - 'A';
                int np = (p - shift) % N;
                if (np < 0) np += N;
                ch = char('A' + np);
            } else if ('a' <= ch && ch <= 'z') {
                int p = 26 + (ch - 'a');
                int np = (p - shift) % N;
                if (np < 0) np += N;
                if (np < 26) ch = char('A' + np);
                else ch = char('a' + (np - 26));
            }
        }

        cout << s << "\n";
    }
    return 0;
}