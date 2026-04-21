/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    string A;

    if (!(cin >> V >> E)) return 0;
    cin >> A;

    if (A != "pedra" && A != "graveto") {
        cout << "Tarzan nao consegue lutar sem armas... Ele foi capturado" << endl;
        return 0;
    }

    int dmg = 0;
    int cost = 0;

    if (A == "pedra") {
        dmg = 15;
        cost = 13;
    } else {
        dmg = 10;
        cost = 8;
    }

    while (V > 0) {
        V -= dmg;
        E -= cost;
        if (E <= 0) {
            cout << "Tarzan nao foi capaz de derrotar o invasor... Ele foi capturado" << endl;
            return 0;
        }
    }

    cout << "Tarzan venceu o invasor e o expulsou de sua floresta" << endl;

    return 0;
}

