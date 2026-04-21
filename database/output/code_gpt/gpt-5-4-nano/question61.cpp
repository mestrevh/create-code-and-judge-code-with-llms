/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X1, Y1, X2, Y2;
    while (cin >> X1 >> Y1 >> X2 >> Y2) {
        if (X1 == 0 && Y1 == 0 && X2 == 0 && Y2 == 0) break;

        int ans;
        if (X1 == X2 && Y1 == Y2) ans = 0;
        else if (X1 == X2 || Y1 == Y2 || abs(X1 - X2) == abs(Y1 - Y2)) ans = 1;
        else ans = 2;

        cout << ans << "\n";
    }
    return 0;
}