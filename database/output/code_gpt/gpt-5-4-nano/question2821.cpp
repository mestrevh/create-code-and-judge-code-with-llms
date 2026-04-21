/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dia, opcao;
    double preco;

    cout << "Digite dia da semana: (1-SEG a 7-DOM)\n";
    if (!(cin >> dia)) return 0;
    cout << "Digite preco do produto em reais:\n";
    cin >> preco;
    cout << "Digite a opcao do produto: (2-prata 1-ouro)\n";
    cin >> opcao;

    double finalPreco = preco;

    if ((dia == 1 || dia == 2 || dia == 3) && opcao == 1) {
        finalPreco = preco / 2.0;
    } else if ((dia == 4 || dia == 5) && preco >= 10.0 && preco <= 100.0) {
        finalPreco = preco / 3.0;
    } else if (dia == 6 && opcao == 2) {
        finalPreco = preco * 3.0;
    } else {
        finalPreco = preco * 2.0;
    }

    string nomeDia;
    switch (dia) {
        case 1: nomeDia = "seg"; break;
        case 2: nomeDia = "ter"; break;
        case 3: nomeDia = "qua"; break;
        case 4: nomeDia = "qui"; break;
        case 5: nomeDia = "sex"; break;
        case 6: nomeDia = "sab"; break;
        default: nomeDia = "dom"; break;
    }

    cout << fixed << setprecision(2);
    cout << "O preco do produto no dia " << nomeDia << " e R$ " << finalPreco << "\n";
    return 0;
}