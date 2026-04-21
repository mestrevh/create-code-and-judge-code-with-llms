/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string sit_em;
    char encceja;
    int nota;
    string escola;
    double renda;

    if (!(cin >> sit_em)) return 0;
    if (!(cin >> encceja)) return 0;
    if (!(cin >> nota)) return 0;
    if (!(cin >> escola)) return 0;
    if (!(cin >> renda)) return 0;

    if (sit_em != "CLD" && sit_em != "CVC" && sit_em != "CSC" && sit_em != "NCC") {
        cout << "Informacao sobre ensino medio invalida" << endl;
        return 0;
    }

    bool isento = false;

    if (encceja == 's' && nota >= 400) {
        isento = true;
    } else if (sit_em == "CVC" && escola == "PUB") {
        isento = true;
    } else if ((sit_em == "CLD" || sit_em == "CVC") && (escola == "PUB" || escola == "PCB") && renda <= 1431.00) {
        isento = true;
    }

    if (isento) {
        cout << "Voce terah direito a isencao" << endl;
    } else {
        cout << "Infelizmente voce nao tem direito a isencao" << endl;
    }

    return 0;
}