/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    if (!(cin >> n)) return 0;
    for (int i = 1; i <= 9; i++) {
        cout << n << " X " << i << " = " << n * i;
        if (i != 9) cout << "\n";
    }
    return 0;
}