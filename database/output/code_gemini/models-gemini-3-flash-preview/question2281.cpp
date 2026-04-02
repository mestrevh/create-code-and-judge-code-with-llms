/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int contarDigitos(long long n) {
    if (n < 10) {
        return 1;
    }
    return 1 + contarDigitos(n / 10);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (cin >> n) {
        cout << contarDigitos(n) << endl;
    }

    return 0;
}