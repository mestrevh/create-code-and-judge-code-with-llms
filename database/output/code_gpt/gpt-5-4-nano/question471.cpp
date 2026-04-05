/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    int miguel = 0, maria = 0;
    int wins = 0;

    auto winner = [&](const string& x, const string& y) -> int {
        string s1, s2;
        s1.reserve(x.size());
        s2.reserve(y.size());
        for (char c : x) if (isalpha((unsigned char)c)) s1.push_back((char)tolower((unsigned char)c));
        for (char c : y) if (isalpha((unsigned char)c)) s2.push_back((char)tolower((unsigned char)c));

        if (s1 == s2) return 0;
        if (s1 == "papel" && s2 == "pedra") return 1;
        if (s1 == "pedra" && s2 == "tesoura") return 1;
        if (s1 == "tesoura" && s2 == "papel") return 1;
        return -1;
    };

    while (wins < 5 && (cin >> a)) {
        if (!(cin >> b)) break;
        int w = winner(a, b);
        if (w == 0) continue;
        if (w == 1) miguel++;
        else maria++;
        wins++;
    }

    if (miguel > maria) cout << "MIGUEL\n";
    else cout << "MARIA\n";
    return 0;
}