/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned long long qtd_de_apostas, k;
    if (cin >> qtd_de_apostas >> k) {
        unsigned long long aposta = 1ULL + (qtd_de_apostas * k);
        cout << aposta << "\n";
    }

    return 0;
}