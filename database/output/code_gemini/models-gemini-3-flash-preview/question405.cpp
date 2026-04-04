/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int ContaDigitosPares(long long n) {
    if (n < 0) n = -n;
    if (n < 10) {
        return (n % 2 == 0) ? 1 : 0;
    }
    return (n % 2 == 0 ? 1 : 0) + ContaDigitosPares(n / 10);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (cin >> n) {
        cout << ContaDigitosPares(n) << endl;
    }

    return 0;
}