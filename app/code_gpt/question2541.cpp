/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double total;
    cout << "Digite o valor total do premio em dinheiro:\n";
    cin >> total;

    double primeiro = total * 0.6;
    double segundo = total * 0.3;
    double terceiro = total * 0.1;

    cout << fixed << setprecision(1);
    cout << "Premio para o 1 lugar: R$ " << primeiro << endl;
    cout << "Premio para o 2 lugar: R$ " << segundo << endl;
    cout << "Premio para o 3 lugar: R$ " << terceiro << endl;

    return 0;
}
