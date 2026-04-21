/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C;
    if (!(cin >> C)) return 0;
    string s;
    cin >> s;
    long long ans = 0;

    for (char ch : s) {
        if (ch == 'P' || ch == 'A') ans += 2;
        else if (ch == 'C') ans += 1;
        else if (ch == 'D') ans += 0;
    }

    cout << ans << "\n";
    return 0;
}