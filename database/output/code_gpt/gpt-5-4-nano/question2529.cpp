/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B;
    if (!(cin >> A)) return 0;
    if (!(cin >> B)) return 0;

    if (A > B) cout << "A eh maior";
    else if (B > A) cout << "B eh maior";
    else cout << "iguais";

    return 0;
}