/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    long long qtd_de_apostas, k;
    cin >> qtd_de_apostas >> k;
    long long aposta = 1 + (qtd_de_apostas * k);
    cout << aposta << endl;
    return 0;
}
