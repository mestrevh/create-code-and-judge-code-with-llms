/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    if (!(cin >> x)) return 0;
    int ans = (x % 2 == 0) ? 1 : -1;
    cout << ans;
    return 0;
}