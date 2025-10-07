/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

int main() {
    string texto;
    char letra;
    getline(cin, texto);
    cin >> letra;

    int contador = 0;
    int totalLetras = 0;

    for (char c : texto) {
        if (isalpha(c)) totalLetras++;
        if (tolower(c) == tolower(letra)) contador++;
    }

    double porcentagem = (totalLetras > 0) ? (static_cast<double>(contador) / totalLetras) * 100 : 0;

    cout << contador << endl;
    cout << fixed << setprecision(2) << porcentagem << "%" << endl;

    return 0;
}
