/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int numPessoas;
    string cidade;
    int quartos;
    double valorCasa, passeioPorPessoa, valorTotal;

    cin >> numPessoas;
    cin >> cidade;
    cin >> quartos;

    if (cidade == "PIPA") {
        if (quartos == 2) {
            valorCasa = 600.0;
        } else {
            valorCasa = 900.0;
        }
        passeioPorPessoa = 75.0;
    } else {
        if (quartos == 3) {
            valorCasa = 950.0;
        } else {
            valorCasa = 1120.0;
        }
        passeioPorPessoa = 60.0;
    }

    valorTotal = valorCasa + (passeioPorPessoa * numPessoas);
    double valorPorPessoa = valorTotal / numPessoas;

    cout << fixed << setprecision(2) << valorTotal << endl;
    cout << fixed << setprecision(2) << valorPorPessoa << endl;

    return 0;
}
