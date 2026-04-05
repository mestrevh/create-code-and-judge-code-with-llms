/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X, Y, Z;
    if (!(cin >> X >> Y >> Z)) return 0;

    long long count = 0;
    bool firstInLine = true;

    for (long long v = 1; v <= Y; v += Z) {
        if (count % X == 0) {
            if (!firstInLine) cout << "\n";
            firstInLine = false;
        } else {
            cout << " ";
        }
        cout << v;
        count++;
    }
    if (count > 0 && count % X != 0) cout << "\n";
    return 0;
}