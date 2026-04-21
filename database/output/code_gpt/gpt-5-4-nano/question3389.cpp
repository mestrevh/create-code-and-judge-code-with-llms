/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double price;
    char cat;
    if (!(cin >> price)) return 0;
    if (!(cin >> cat)) return 0;

    cat = (char)toupper((unsigned char)cat);

    if (cat == 'E') {
        double finalPrice = price * 0.5;
        cout << fixed << setprecision(2);
        cout << "Preco com desconto: R$" << finalPrice << "\n";
        cout << "Categoria: Estudante";
    } else if (cat == 'A') {
        double finalPrice = price * 0.7;
        cout << fixed << setprecision(2);
        cout << "Preco com desconto: R$" << finalPrice << "\n";
        cout << "Categoria: Aposentado";
    } else if (cat == 'N') {
        cout << fixed << setprecision(2);
        cout << "Preco: R$" << price << "\n";
        cout << "Categoria: Normal";
    } else {
        cout << "Categoria invalida";
    }

    return 0;
}