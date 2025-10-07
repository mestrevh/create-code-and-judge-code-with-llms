/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int quantidade;
    cout << "Digite a quantidade de macas:" << endl;
    cin >> quantidade;

    double preco = (quantidade < 12) ? 0.30 : 0.25;
    double total = quantidade * preco;

    cout << "Valor total: R$ " << fixed << setprecision(2) << total << endl;

    return 0;
}
