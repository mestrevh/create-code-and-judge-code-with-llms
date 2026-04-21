/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long h, m, s;
    if (!(cin >> h >> m >> s)) return 0;
    cout << h * 3600 + m * 60 + s;
    return 0;
}