/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    int total = 42;
    int livres = total - n;
    double receita = livres * 1.75;

    cout.setf(ios::fixed);
    cout << setprecision(2) << receita << "\n";
    return 0;
}