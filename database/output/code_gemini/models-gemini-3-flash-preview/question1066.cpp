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

    double temperatura;
    string resposta;

    if (!(cin >> temperatura)) return 0;
    if (!(cin >> resposta)) return 0;

    if (resposta != "S" && resposta != "N") {
        cout << "Erro" << endl;
    } else {
        if (temperatura >= 37.0) {
            if (resposta == "S") {
                cout << "Exames Especiais" << endl;
            } else {
                cout << "Exames Basicos" << endl;
            }
        } else {
            if (resposta == "S") {
                cout << "Exames Basicos" << endl;
            } else {
                cout << "Liberado" << endl;
            }
        }
    }

    return 0;
}