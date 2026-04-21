/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    char c;
    if (!(cin >> n >> c)) return 0;

    auto isSpecial = [&](char ch) {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return false;
        if (ch >= '0' && ch <= '9') return false;
        return true;
    };

    auto isVowel = [&](char ch) {
        ch = (char)tolower((unsigned char)ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    };

    int ans = 4;
    if (isSpecial(c) && n >= 0 && n <= 99) ans = 1;
    else if (n % 2 == 0 && isVowel(c)) ans = 2;
    else if (n % 2 == 1 && c >= 'A' && c <= 'Z') ans = 3;
    else ans = 4;

    cout << "Caminhão " << ans;
    return 0;
}