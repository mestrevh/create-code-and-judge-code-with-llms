/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c;
    if (!(cin >> a >> b >> c)) return 0;
    cout << (a + b > c && a + c > b && b + c > a ? 1 : 0);
    return 0;
}