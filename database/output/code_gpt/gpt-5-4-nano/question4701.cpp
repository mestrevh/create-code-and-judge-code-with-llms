/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string palavra;
    if (!getline(cin, palavra)) return 0;

    string frase;
    if (!getline(cin, frase)) return 0;

    auto normalize = [](unsigned char c) -> unsigned char {
        if (c >= 'A' && c <= 'Z') return (unsigned char)(c - 'A' + 'a');
        return c;
    };

    for (char &ch : palavra) ch = (char)normalize((unsigned char)ch);

    string s = frase;
    for (char &ch : s) ch = (char)normalize((unsigned char)ch);

    long long ans = 0;
    string token;
    for (char ch : s) {
        if (isalnum((unsigned char)ch)) token.push_back(ch);
        else {
            if (!token.empty()) {
                if (token == palavra) ans++;
                token.clear();
            }
        }
    }
    if (!token.empty() && token == palavra) ans++;

    cout << ans << "\n";
    return 0;
}