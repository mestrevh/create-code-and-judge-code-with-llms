/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int C;
    cin >> C;
    
    if (C < 1000 || C > 9999) {
        cout << "Charmander derrotado" << endl;
        return 0;
    }

    int AB = C / 100; // pegar os dois primeiros dígitos
    int CD = C % 100; // pegar os dois últimos dígitos
    int EF = AB + CD;

    if (EF * EF == C) {
        cout << "Charmander vitorioso" << endl;
    } else {
        cout << "Charmander derrotado" << endl;
    }

    return 0;
}
