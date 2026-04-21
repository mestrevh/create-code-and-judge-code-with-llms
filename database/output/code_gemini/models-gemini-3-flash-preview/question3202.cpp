/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long double custo, preco;
    if (!(cin >> custo >> preco)) return 0;

    if (preco <= 0) return 0;

    long long res1 = (long long)ceill(custo / preco);
    long long res2 = (long long)ceill((custo * 1.23L) / preco);

    cout << res1 << "\n" << res2 << "\n";

    return 0;
}