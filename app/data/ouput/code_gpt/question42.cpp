/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int idade;
    cin >> idade;

    if (idade < 16) {
        cout << "nao eleitor" << endl;
    } else if (idade >= 18 && idade <= 65) {
        cout << "eleitor obrigatorio" << endl;
    } else {
        cout << "eleitor facultativo" << endl;
    }

    return 0;
}
