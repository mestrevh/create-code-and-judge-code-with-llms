/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int idade;
    while (true) {
        cin >> idade;
        if (idade == 0) break;
        if (idade < 0) {
            cout << "Você ainda não nasceu." << endl;
        } else if (idade < 16) {
            cout << "Você não pode votar." << endl;
        } else if (idade >= 18 && idade <= 70) {
            cout << "Você tem a obrigatoriedade de votar." << endl;
        } else {
            cout << "Na sua idade, o voto é opcional." << endl;
        }
    }
    return 0;
}
