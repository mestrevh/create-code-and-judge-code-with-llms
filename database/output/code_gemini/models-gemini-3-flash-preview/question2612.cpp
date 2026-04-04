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

    string situacao;
    if (!(cin >> situacao)) return 0;

    // First check: Valid high school situation
    if (situacao != "CLD" && situacao != "CVC" && situacao != "CSC" && situacao != "NCC") {
        cout << "Informacao sobre ensino medio invalida" << endl;
        return 0;
    }

    string fezEncceja;
    cin >> fezEncceja;
    int notaEncceja;
    cin >> notaEncceja;
    string escola;
    cin >> escola;
    double renda;
    cin >> renda;
    string isencao2018;
    cin >> isencao2018;

    bool eligible = false;

    // Profile 1: Last year of high school (CVC) in public school (PUB)
    if (situacao == "CVC" && escola == "PUB") {
        eligible = true;
    }

    // Profile 2: Encceja 2018 certification with minimum 400 points
    if (fezEncceja == "s" && notaEncceja >= 400) {
        eligible = true;
    }

    // Profile 3: Entire high school in public (PUB) or as full scholarship holder in private (PCB)
    // and income per capita <= R$ 1.431,00.
    // Based on "fizeram todo e concluíram", this typically applies to those who have finished (CLD)
    // or are in the process of finishing their final year (CVC).
    if ((situacao == "CLD" || situacao == "CVC") && (escola == "PUB" || escola == "PCB") && renda <= 1431.00) {
        eligible = true;
    }

    if (eligible) {
        cout << "Você terah direito a isencao" << endl;
    } else {
        cout << "Infelizmente voce nao tem direito a isencao" << endl;
    }

    return 0;
}