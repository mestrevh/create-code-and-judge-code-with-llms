/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int i;
    if (!(cin >> i)) return 0;

    const vector<string> pattern = {
        "rosa rosa verde rosa",
        "verde rosa verde rosa",
        "rosa rosa rosa verde",
        "verde rosa rosa verde",
        "rosa verde verde rosa",
        "verde verde verde rosa",
        "rosa verde rosa verde",
        "verde verde rosa verde",
        "rosa rosa verde azul",
        "verde rosa verde azul",
        "rosa rosa rosa azul",
        "verde rosa rosa azul"
    };

    if (0 <= i && i <= 11) cout << pattern[i] << "\n";
    return 0;
}