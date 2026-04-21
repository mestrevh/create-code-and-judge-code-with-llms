/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void printEvenDesc(int n) {
    if (n < 0) return;
    cout << n << "\n";
    printEvenDesc(n - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;

    if (N % 2 != 0) N--;
    printEvenDesc((int)N);
    return 0;
}