/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    char genero;
    cin >> genero;

    if (genero == 'M' || genero == 'm') {
        cout << "Masculino" << endl;
    } else if (genero == 'F' || genero == 'f') {
        cout << "Feminino" << endl;
    } else {
        cout << "Genero nao especificado" << endl;
    }

    return 0;
}
