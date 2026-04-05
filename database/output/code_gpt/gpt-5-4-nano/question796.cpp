/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N1, N2;
    while (cin >> N1 >> N2) {
        int a = 1, b = 1;
        for (int i = 0; i < N1; i++) a = (a * N1) % 100;
        for (int i = 0; i < N2; i++) b = (b * N2) % 100;

        if (a > b) cout << N1 << "\n";
        else if (b > a) cout << N2 << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}