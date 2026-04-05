/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

bool haPredOuSuccRec(int n, int x) {
    if (n == 0) return false;
    int d = n % 10;
    if (d == x - 1 || d == x + 1) return true;
    return haPredOuSuccRec(n / 10, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    int x;
    if (!(cin >> n >> x)) return 0;

    if (n == 0) {
        cout << "nao";
        return 0;
    }

    cout << (haPredOuSuccRec((int)n, x) ? "sim" : "nao");
    return 0;
}