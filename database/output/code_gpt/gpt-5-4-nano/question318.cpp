/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, R;
    while (cin >> L >> R) {
        if (L == 0 && R == 0) break;
        cout << (L + R) << "\n";
    }
    return 0;
}