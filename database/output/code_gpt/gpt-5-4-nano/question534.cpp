/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static int firstVerifier(const array<int,9>& a) {
    int sum = 0;
    for (int j = 1; j <= 9; j++) {
        int Nj = a[j-1];
        int i = (11 - j);
        sum += Nj * i;
    }
    int r = sum % 11;
    if (r < 2) return 0;
    return 11 - r;
}

static int secondVerifier(const array<int,9>& a, int d1) {
    int sum = 0;
    for (int j = 1; j <= 10; j++) {
        int Nj = (j <= 9) ? a[j-1] : d1;
        int i = (12 - j);
        sum += Nj * i;
    }
    int r = sum % 11;
    if (r < 2) return 0;
    return 11 - r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    for (int tc = 1; tc <= T; tc++) {
        array<int,9> a{};
        for (int i = 0; i < 9; i++) cin >> a[i];

        int d1 = firstVerifier(a);
        int d2 = secondVerifier(a, d1);

        cout << "Caso " << tc << ": ";
        for (int i = 0; i < 9; i++) cout << a[i];
        cout << "-" << d1 << d2 << "\n";
    }
    return 0;
}