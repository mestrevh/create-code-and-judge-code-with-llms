/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string dia, opcao, nome;
    double preco;

    if (!(cin >> dia)) return 0;
    if (!(cin >> preco)) return 0;
    cin >> opcao;
    cin >> nome;

    double finalPrice = preco;

    if ((dia == "seg" || dia == "ter" || dia == "qua") && opcao == "ouro") {
        finalPrice = preco / 2.0;
    } else if ((dia == "qui" || dia == "sex") && preco >= 10.0 && preco <= 100.0) {
        finalPrice = preco / 3.0;
    } else if (dia == "sab" && opcao == "prata") {
        finalPrice = preco * 3.0;
    } else {
        finalPrice = preco * 2.0;
    }

    cout.setf(ios::fixed);
    cout << setprecision(2);

    cout << "O preco do produto " << nome << " no dia " << dia << " eh " << finalPrice << "\n";
    return 0;
}