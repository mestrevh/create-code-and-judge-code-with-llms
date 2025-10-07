/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    float temperatura;
    char resposta;
    
    cin >> temperatura >> resposta;

    if (resposta != 'S' && resposta != 'N') {
        cout << "Erro" << endl;
    } else if (temperatura >= 37) {
        if (resposta == 'S') {
            cout << "Exames Especiais" << endl;
        } else {
            cout << "Exames Basicos" << endl;
        }
    } else {
        if (resposta == 'S') {
            cout << "Exames Basicos" << endl;
        } else {
            cout << "Liberado" << endl;
        }
    }

    return 0;
}
