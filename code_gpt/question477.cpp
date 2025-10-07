/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int forca, inteligencia, destreza, furtividade, peso;
    cin >> forca >> inteligencia >> destreza >> furtividade >> peso;

    if (forca > 5 && inteligencia <= 5 && destreza > 5 && furtividade <= 5 && peso > 5) {
        cout << "Knight" << endl;
    } else if (forca < 5 && inteligencia > 5 && destreza <= 5 && furtividade > 5 && peso < 5) {
        cout << "Mage" << endl;
    } else if (forca > 5 && inteligencia > 5 && destreza > 5 && furtividade > 5 && peso < 5) {
        cout << "Paladin" << endl;
    } else if (forca > 10 && inteligencia < 5 && destreza < 5 && furtividade < 5 && peso > 5) {
        cout << "Orc" << endl;
    } else {
        cout << "Desconhecido" << endl;
    }

    return 0;
}
