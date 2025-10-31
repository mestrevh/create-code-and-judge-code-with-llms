/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string situacao, fez_encceja, tipo_escola, isencao;
    int nota = -1;
    double renda;

    cin >> situacao >> fez_encceja >> nota >> tipo_escola >> renda >> isencao;

    if (situacao != "CLD" && situacao != "CVC" && situacao != "CSC" && situacao != "NCC") {
        cout << "Informacao sobre ensino medio invalida" << endl;
        return 0;
    }

    bool tem_direito = false;

    if (situacao == "CLD") {
        tem_direito = true;
    } else if (situacao == "CVC") {
        if (fez_encceja == "s" && nota >= 400) {
            tem_direito = true;
        } else if (fez_encceja == "n") {
            if (renda <= 1431.00) {
                tem_direito = true;
            }
        }
    } else if (situacao == "CSC") {
        if (renda <= 1431.00) {
            tem_direito = true;
        }
    } else if (situacao == "NCC") {
        tem_direito = false;
    }

    if (tem_direito) {
        if (isencao == "s" && (situacao == "CLD" || situacao == "CVC")) {
            cout << "Infelizmente voce nao tem direito a isencao" << endl;
        } else {
            cout << "Voce terah direito a isencao" << endl;
        }
    } else {
        cout << "Infelizmente voce nao tem direito a isencao" << endl;
    }

    return 0;
}
