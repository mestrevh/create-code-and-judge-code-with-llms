/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long sorvetes(long long tempo, long long T) {
    return tempo / T;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long B, K, T;
    if (!(cin >> B >> K >> T)) return 0;

    long long X = sorvetes(B, T);
    long long Y = sorvetes(K, T);

    cout << "Badtz-Maru comeu " << X << " sorvetes.\n";
    cout << "Keroppi comeu " << Y << " sorvetes.\n";
    return 0;
}