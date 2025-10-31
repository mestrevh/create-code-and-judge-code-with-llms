/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    char nacionalidade;
    char ocupacao;
    int quantidade;
    int calibre;

    while (true) {
        cin >> nacionalidade;
        if (nacionalidade != 'B' && nacionalidade != 'E') break;

        cin >> ocupacao;
        cin >> quantidade;

        if (quantidade > 0) {
            for (int i = 0; i < quantidade; i++) {
                cin >> calibre;
            }
        }
        
        if (nacionalidade == 'E') {
            if (quantidade == 0) {
                cout << "Liberado" << endl;
            } else {
                cout << "Barrado" << endl;
            }
        } else {
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
    }

    cout << "Fim" << endl;
    return 0;
}
