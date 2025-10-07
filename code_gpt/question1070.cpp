/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string dia, opcao, nome;
    float preco;

    cin >> dia >> preco >> opcao;
    cin.ignore();
    getline(cin, nome);

    if (dia == "seg" || dia == "ter" || dia == "qua") {
        if (opcao == "ouro") {
            preco /= 2;
        }
    } else if (dia == "qui" || dia == "sex") {
        if (preco >= 10.0 && preco <= 100.0) {
            preco /= 3;
        }
    } else if (dia == "sab" && opcao == "prata") {
        preco *= 3;
    } else {
        preco *= 2;
    }

    cout << fixed << setprecision(2);
    cout << "O preco do produto " << nome << " no dia " << dia << " eh " << preco << endl;

    return 0;
}
