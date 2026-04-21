/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int idade;
    while (cin >> idade && idade != 0) {
        if (idade < 0) {
            cout << "Você ainda não nasceu." << "\n";
        } else if (idade <= 11) {
            cout << "Você é uma criança." << "\n";
        } else if (idade <= 17) {
            cout << "Você é um adolescente." << "\n";
        } else if (idade <= 35) {
            cout << "Você é um jovem." << "\n";
        } else if (idade <= 64) {
            cout << "Você é um adulto." << "\n";
        } else {
            cout << "Você é um idoso." << "\n";
        }
    }

    return 0;
}