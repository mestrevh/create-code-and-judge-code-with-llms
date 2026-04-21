/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long idade;
    if (!(cin >> idade)) return 0;
    cout << idade * 365LL * 24LL * 60LL * 60LL;
    return 0;
}