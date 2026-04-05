/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long s;
    if (!(cin >> s)) return 0;

    long long h = s / 3600;
    s %= 3600;
    long long m = s / 60;
    long long sec = s % 60;

    cout << h << " h " << m << " m " << sec << " s";
    return 0;
}