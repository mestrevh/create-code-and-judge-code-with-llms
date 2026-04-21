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

    vector<string> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<string> out(N, string(N, ' '));

    auto transformChar = [](char c) -> char {
        if (c >= 'a' && c <= 'y') return char(c + 1);
        if (c == 'z') return 'b';
        return c;
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char ch = a[j][i];
            out[i][j] = transformChar(ch);
        }
    }

    for (int i = 0; i < N; i++) cout << out[i] << "\n";
    return 0;
}