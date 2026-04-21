/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!getline(cin, s)) return 0;

    size_t i = 0, j = s.size();
    if (j > 0) j--;
    bool ok = true;

    while (i < j) {
        if (s[i] != s[j]) {
            ok = false;
            break;
        }
        i++;
        j--;
    }

    cout << (ok ? "True" : "False");
    return 0;
}