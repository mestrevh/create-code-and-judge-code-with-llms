/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long fact[13];
    fact[0] = 1;
    for (int i = 1; i <= 12; ++i) {
        fact[i] = fact[i - 1] * i;
    }

    int n;
    while (cin >> n && n != -1) {
        if (n >= 0 && n <= 12) {
            cout << fact[n] << "\n";
        }
    }

    return 0;
}