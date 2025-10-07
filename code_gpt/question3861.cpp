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
        } else if (idade >= 1 && idade <= 11) {
            cout << "Você é uma criança." << endl;
        } else if (idade >= 12 && idade <= 17) {
            cout << "Você é um adolescente." << endl;
        } else if (idade >= 18 && idade <= 35) {
            cout << "Você é um jovem." << endl;
        } else if (idade >= 36 && idade <= 64) {
            cout << "Você é um adulto." << endl;
        } else {
            cout << "Você é um idoso." << endl;
        }
    }
    return 0;
}
