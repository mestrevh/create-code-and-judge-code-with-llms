/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string situacao, fez_encceja, escola_tipo;
    int nota;
    double renda;
    
    cin >> situacao >> fez_encceja >> nota >> escola_tipo >> renda;

    if (situacao != "CLD" && situacao != "CVC" && situacao != "CSC" && situacao != "NCC") {
        cout << "Informacao sobre ensino medio invalida" << endl;
        return 0;
    }
    
    bool isento = false;
    
    if (situacao == "CLD") {
        isento = true;
    } else if (situacao == "CVC") {
        if (fez_encceja == "s" && nota >= 400) {
            isento = true;
        }
    } else if (situacao == "CSC") {
        isento = (fez_encceja == "n" && renda <= 1431.0);
    } else if (situacao == "NCC") {
        isento = false;
    }
    
    if (isento) {
        cout << "Voce terah direito a isencao" << endl;
    } else {
        cout << "Infelizmente voce nao tem direito a isencao" << endl;
    }
    
    return 0;
}
