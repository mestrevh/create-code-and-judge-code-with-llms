/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    while (cin >> S) {
        if (S == "0") break;
        int n = (int)S.size();
        unsigned long long res = 1;
        for (int i = 2; i <= n; i++) res *= (unsigned long long)i;
        cout << res << "\n";
    }
    return 0;
}