/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    char nacionalidade, ocupacao;
    int quantidade, calibre;
    
    cin >> nacionalidade >> ocupacao >> quantidade >> calibre;

    if (nacionalidade == 'E') {
        if (quantidade == 0 && calibre == 0) {
            cout << "Liberado" << endl;
        } else {
            cout << "Barrado" << endl;
        }
    } else if (nacionalidade == 'B') {
        if (ocupacao == 'M') {
            cout << "Liberado" << endl;
        } else if (ocupacao == 'T' || ocupacao == 'O') {
            if (quantidade == 1 && calibre <= 22) {
                cout << "Liberado" << endl;
            } else {
                cout << "Barrado" << endl;
            }
        } else if (ocupacao == 'C') {
            if (quantidade <= 2 && calibre <= 38) {
                cout << "Liberado" << endl;
            } else {
                cout << "Barrado" << endl;
            }
        }
    }
    
    return 0;
}
