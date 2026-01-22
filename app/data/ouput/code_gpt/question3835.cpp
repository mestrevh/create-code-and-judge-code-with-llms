/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int t[8];
    for (int i = 0; i < 8; i++) {
        cin >> t[i];
    }

    bool valid = true;

    // Alan deve estar com uma menina (Bianca, Daniela, Fernanda, Helen)
    if (t[0] != 2 && t[3] != 2 && t[5] != 2 && t[7] != 2) valid = false;

    // Bianca não pode estar com Alan ou Daniela
    if (t[1] == 1 || t[1] == 1) valid = false;

    // Se Gabriel jogar com Helen, Daniela precisa jogar com Carlos
    if (t[6] == 4 && t[7] == 4 && !(t[3] == 3 && t[2] == 1)) valid = false;

    // Helen só jogando com Gabriel ou Fernanda
    if (t[7] == 4 && t[6] != 4 && t[5] != 3) valid = false;

    // Se Carlos joga com Erasmo, Fernanda jogará com Alan
    if (t[2] == 3 && t[4] == 3 && t[0] != 3) valid = false;
    
    // Se Carlos joga com outras pessoas, Fernanda não jogará com Alan
    if (t[2] != 3 && t[0] == 3) valid = false;

    if (valid) {
        cout << "Conseguimos times suficientes!" << endl;
    } else {
        cout << "Alguem nao esta satisfeito..." << endl;
    }

    return 0;
}
