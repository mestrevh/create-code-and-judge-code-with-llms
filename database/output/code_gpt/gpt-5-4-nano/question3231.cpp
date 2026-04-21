/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    if (!(cin >> n)) return 0;
    bool ok = (n % 4 == 0) && (n % 7 == 0) && (n % 5 != 0);
    cout << (ok ? "sim" : "nao");
    return 0;
}