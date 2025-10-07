/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int capacidadeMaxima, adultos, criancas, convidados;

    cin >> capacidadeMaxima;

    while (true) {
        cin >> adultos;
        if (adultos < 0) break;
        cin >> criancas >> convidados;

        int totalCriancas = criancas + convidados;
        
        if (convidados > 0) {
            cout << "Acesso permitido devido a presenca de convidado(s).\n";
        } else if (totalCriancas > capacidadeMaxima) {
            cout << "Capacidade maxima de criancas atingida/excedida.\n";
            cout << "Tem " << totalCriancas - capacidadeMaxima << " crianca(s) a mais que as " << capacidadeMaxima << " permitidas.\n";
        } else {
            cout << "Acesso permitido!\n";
        }

        cout << "Adultos na piscina: " << adultos << "\n";
        cout << "Criancas na piscina: " << totalCriancas << "\n";
        cout << "***\n";
    }

    return 0;
}
