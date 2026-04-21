/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int qtdDigitos(unsigned int n) {
    if (n == 0) return 1;
    int cnt = 0;
    while (n > 0) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

int main() {
    unsigned int n;
    if (!(cin >> n)) return 0;
    cout << qtdDigitos(n);
    return 0;
}