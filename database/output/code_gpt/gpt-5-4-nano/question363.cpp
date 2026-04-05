/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;

    long long P, Q;
    char C;
    cin >> P >> C >> Q;

    bool overflow = false;
    if (C == '+') {
        overflow = (P + Q > N);
    } else {
        if (P == 0 || Q == 0) overflow = false;
        else overflow = (P * Q > N);
    }

    cout << (overflow ? "OVERFLOW" : "OK") << "\n";
    return 0;
}