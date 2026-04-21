/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void printEvens(int n) {
    if (n < 0) return;
    if (n == 0) {
        cout << 0 << "\n";
        return;
    }
    if (n % 2 == 1) {
        printEvens(n - 1);
        return;
    }
    printEvens(n - 2);
    cout << n << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N;
    if (!(cin >> N)) return 0;
    if (N < 0) return 0;
    if (N == 0) {
        cout << 0 << "\n";
        return 0;
    }
    printEvens((int)N);
    return 0;
}