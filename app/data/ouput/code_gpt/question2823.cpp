/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int rodada, soma[3], ganhou = 0, perdeu = 0;
    
    cout << "Digite a soma dos dados em cada rodada separados por ENTER:" << endl;
    for (int i = 0; i < 3; i++) {
        cin >> rodada;
        if (rodada < 2 || rodada > 12) {
            cout << "Valor invalido" << endl;
            return 0;
        }
        soma[i] = rodada;
        if (rodada == 2) {
            perdeu = 1;
            break;
        }
        if (rodada >= 10 || rodada <= 4) ganhou = 1;
        if (rodada % 2 == 0) ganhou = 1;
    }

    if (perdeu) {
        cout << "Biu perdeu" << endl;
    } else if (ganhou) {
        cout << "Biu ganhou" << endl;
    } else {
        cout << "Biu perdeu" << endl;
    }

    return 0;
}
