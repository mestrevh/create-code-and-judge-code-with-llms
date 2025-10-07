/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int dia, opcao;
    float preco;

    cout << "Digite dia da semana: (1-SEG a 7-DOM)\n";
    cin >> dia;
    cout << "Digite preco do produto em reais:\n";
    cin >> preco;
    cout << "Digite a opcao do produto: (2-prata 1-ouro)\n";
    cin >> opcao;

    if ((dia >= 1 && dia <= 3) && (opcao == 1)) {
        preco /= 2;
    } else if ((dia == 4 || dia == 5) && (preco >= 10 && preco <= 100)) {
        preco /= 3;
    } else if (dia == 6 && opcao == 2) {
        preco *= 3;
    } else {
        preco *= 2;
    }

    cout << fixed << setprecision(2);
    cout << "O preco do produto no dia ";
    switch(dia) {
        case 1: cout << "seg"; break;
        case 2: cout << "ter"; break;
        case 3: cout << "qua"; break;
        case 4: cout << "qui"; break;
        case 5: cout << "sex"; break;
        case 6: cout << "sab"; break;
        case 7: cout << "dom"; break;
    }
    cout << " e R$ " << preco << endl;

    return 0;
}
