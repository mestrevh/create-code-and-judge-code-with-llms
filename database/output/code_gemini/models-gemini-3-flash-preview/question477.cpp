/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int força, inteligência, destreza, furtividade, peso;
    if (!(cin >> força >> inteligência >> destreza >> furtividade >> peso)) {
        return 0;
    }

    if (força > 5 && inteligência > 5 && destreza > 5 && furtividade > 5 && peso < 5) {
        cout << "Paladin" << endl;
    } else if (força < 5 && inteligência > 5 && furtividade > 5 && peso < 5) {
        cout << "Mage" << endl;
    } else if (força > 10 && inteligência < 5 && destreza < 5 && furtividade < 5 && peso > 5) {
        cout << "Orc" << endl;
    } else if (força > 5 && destreza > 5 && peso > 5) {
        cout << "Knight" << endl;
    }

    return 0;
}