/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    if (!(cin >> n >> m)) return 0;

    long long bills = (m + 99) / 100;
    long long cost = bills * 100;

    if (n < cost) {
        cout << "Pedro vai ter que fugir" << endl;
    } else {
        if (cost > m) {
            cout << "Pegou mais" << endl;
        }
        cout << "Esta pago" << endl;
        cout << "Sobrou " << (n - cost) << endl;
    }

    return 0;
}