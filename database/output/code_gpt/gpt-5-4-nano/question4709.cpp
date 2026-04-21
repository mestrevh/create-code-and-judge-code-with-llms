/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    if (!(cin >> n)) return 0;
    for (int i = 1; i <= 10; i++) {
        cout << n << " x " << i << " = " << " " << n * i;
        if (i != 10) cout << "\n";
    }
    return 0;
}