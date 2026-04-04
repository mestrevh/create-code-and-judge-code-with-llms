/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, A;
    if (!(cin >> H >> A)) return 0;

    int tita_pos = 5;
    int soldado_pos = 0;
    bool capturou = false;

    while (tita_pos < 50) {
        tita_pos += H;
        soldado_pos += A;
        
        if (soldado_pos > tita_pos) {
            capturou = true;
            break;
        }
    }

    if (capturou) {
        cout << "Capturamos ele, comandante!" << "\n";
        cout << "altura alcancada pelo tita: " << tita_pos << "\n";
        cout << "altura alcancada pelo soldado: " << soldado_pos << "\n";
    } else {
        cout << "Comandante, a operacao falhou!" << "\n";
        cout << "altura alcancada pelo soldado: " << soldado_pos << "\n";
    }

    return 0;
}