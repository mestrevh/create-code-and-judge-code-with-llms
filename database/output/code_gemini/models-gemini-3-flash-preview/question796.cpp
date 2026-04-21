/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

long long solvePow(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2;
    while (cin >> n1 >> n2) {
        int r1 = (int)solvePow(n1, n1, 100);
        int r2 = (int)solvePow(n2, n2, 100);

        if (r1 > r2) {
            cout << n1 << "\n";
        } else if (r2 > r1) {
            cout << n2 << "\n";
        } else {
            cout << "0\n";
        }
    }

    return 0;
}