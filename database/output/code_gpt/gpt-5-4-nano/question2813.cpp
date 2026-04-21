/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cout << "Digite um numero positivo:";
    if (!(cin >> n)) return 0;

    if (n < 0) {
        cout << "\nApenas valores positivos";
        return 0;
    }

    long double media = (n * (n + 1)) / 2.0L / (long double)n;

    cout << "\nMedia de 1 ate " << n << ": ";
    cout << fixed << setprecision(10) << media;
    string s = to_string((double)media);
    cout.flush();

    return 0;
}