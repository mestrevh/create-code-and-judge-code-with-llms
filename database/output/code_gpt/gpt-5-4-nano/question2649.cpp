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
    cin >> B;

    long long start = A + ((3 - (A % 3 + 3) % 3) % 3);
    for (long long x = start; x <= B; x += 3) {
        cout << x << "\n";
    }
    return 0;
}