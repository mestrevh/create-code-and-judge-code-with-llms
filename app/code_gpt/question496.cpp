/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string tipo, cidade;
    int estrelas;
    int cincoEstrelasJP = 0, totalEstrelasCG = 0, contCG = 0, pousadasRT = 0;

    for (int i = 0; i < 10; i++) {
        cin >> tipo >> estrelas;
        cin.ignore();
        getline(cin, cidade);
        for (auto &c : cidade) c = tolower(c);

        if (cidade == "joão pessoa" && tipo == "hotel" && estrelas == 5) {
            cincoEstrelasJP++;
        }

        if (cidade == "campina grande") {
            totalEstrelasCG += estrelas;
            contCG++;
        }

        if (cidade == "rio tinto" && tipo == "pousada") {
            pousadasRT++;
        }
    }

    int mediaEstrelasCG = contCG > 0 ? totalEstrelasCG / contCG : 0;

    cout << cincoEstrelasJP << endl;
    cout << mediaEstrelasCG << endl;
    cout << pousadasRT << endl;

    return 0;
}
