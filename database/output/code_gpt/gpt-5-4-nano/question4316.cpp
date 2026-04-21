/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long nDigits;
    string a;
    if (!(cin >> nDigits)) return 0;
    cin >> a;

    int i = (int)a.size() - 1;
    while (i > 0 && a[i] == '0') i--;
    string res;
    for (; i >= 0; i--) res.push_back(a[i]);
    if (res.empty()) res = "0";

    cout << res;
    return 0;
}