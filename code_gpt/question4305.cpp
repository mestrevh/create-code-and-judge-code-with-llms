/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double x, y;
    char destino;
    int n;
    
    cin >> x >> y >> destino >> n;

    if ((x < 0 || x >= 24) || (y < 0 || y >= 24) || (x >= y) || (n <= 0) || (destino != 'A' && destino != 'B')) {
        cout << "Entrada Invalida\n";
        return 0;
    }

    double tempoDisponivel = (y - x) * 60; // em minutos
    int capacidade = 5;

    if (destino == 'A') {
        if (tempoDisponivel <= 60) {
            cout << "Infelizmente o uninho nao tanka, rodamos!\n";
            return 0;
        }
    } else {
        if (tempoDisponivel <= 45) {
            cout << "Infelizmente o uninho nao tanka, rodamos!\n";
            return 0;
        }
    }

    if (tempoDisponivel >= 1.5 * ((destino == 'A') ? 60 : 45)) {
        capacidade += 4;
    }

    if (n > capacidade) {
        cout << "Infelizmente o uninho nao tanka, rodamos!\n";
    } else {
        cout << "O uninho faz a boa, obrigado querida mae line\n";
    }
    
    return 0;
}
