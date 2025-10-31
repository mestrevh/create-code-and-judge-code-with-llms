/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string item;
    int anos;
    double valor = 0.0;

    cin >> ws; // Remove espaços em branco iniciais
    getline(cin, item);
    cin >> anos;

    transform(item.begin(), item.end(), item.begin(), ::tolower);

    if (item == "mural") valor = 200.0;
    else if (item == "o coreto") valor = 235.0;
    else if (item == "meu lar") valor = 180.0;
    else if (item == "sua mesa") valor = 230.0;

    if (item == "mural" || item == "o coreto" || item == "meu lar" || item == "sua mesa") {
        cout << fixed << setprecision(2) << valor * anos << endl;
    } else {
        valor = 0.0; // Revistas com desconto
        if (item == "mural") valor = 200.0; // Essa linha é redundante para jornais
        else if (item == "o coreto") valor = 235.0;
        else if (item == "meu lar") valor = 180.0;
        else if (item == "sua mesa") valor = 230.0;

        valor *= 0.9; // Aplicando 10% de desconto
        cout << fixed << setprecision(2) << valor * anos << endl;
    }

    return 0;
}
