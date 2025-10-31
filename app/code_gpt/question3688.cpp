/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int cor;
    string frase;
    getline(cin, frase);
    cin >> cor;

    int letras = frase.size();
    float preco1, preco2;

    if (letras <= 10) {
        preco1 = (cor == 1) ? 2 : 6;
        preco2 = (cor == 1) ? 4 : 9;
    } else if (letras <= 30) {
        preco1 = (cor == 1) ? 0.45 * letras : 0.15 * letras;
        preco2 = (cor == 1) ? 0.75 * letras : 0.25 * letras;
    } else {
        preco1 = (cor == 1) ? 0.20 * letras : 0.10 * letras;
        preco2 = (cor == 1) ? 0.75 * letras : 0.25 * letras;
    }

    float custo1 = (cor == 1) ? preco1 : preco2;
    float custo2 = (cor == 1) ? preco2 : preco1;

    if (custo1 < custo2) {
        cout << "A grafica 1 eh a mais em conta" << endl;
        cout << fixed << setprecision(2) << "O preco sera: $" << custo1 << endl;
    } else {
        cout << "A grafica 2 eh a mais em conta" << endl;
        cout << fixed << setprecision(2) << "O preco sera: $" << custo2 << endl;
    }

    return 0;
}
