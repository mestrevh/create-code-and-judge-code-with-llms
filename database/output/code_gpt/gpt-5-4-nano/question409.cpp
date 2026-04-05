/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int SerieMiguelito(int n) {
    if (n == 1) return 3;
    if (n % 2 == 0) return SerieMiguelito(n - 1) + 4;
    return SerieMiguelito(n - 1) + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    cout << SerieMiguelito(n) << "\n";
    return 0;
}