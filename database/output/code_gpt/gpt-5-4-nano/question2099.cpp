/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string situacao, encceja;
    int nota;
    string tipoEscola;
    double renda;

    if (!(cin >> situacao)) return 0;
    cin >> encceja;
    cin >> nota;
    cin >> tipoEscola;
    cin >> renda;

    const double LIMIAR_RENDA = 1431.00;

    bool temDireito = false;

    if (situacao == "CVC") {
        temDireito = true;
    } else if (situacao == "CLD") {
        if (encceja == "s" && nota >= 400 && nota <= 800) {
            temDireito = true;
        } else {
            if (tipoEscola == "PUB") temDireito = true;
            if (tipoEscola == "PCB") {
                if (renda <= LIMIAR_RENDA) temDireito = true;
            }
            if (tipoEscola == "PSB" || tipoEscola == "PPS" || tipoEscola == "PPB") {
                if (renda <= LIMIAR_RENDA) temDireito = true;
            }
        }
    } else if (situacao == "CSC") {
        temDireito = false;
    } else if (situacao == "NCC") {
        if (encceja == "s" && nota >= 400 && nota <= 800) temDireito = true;
        else temDireito = false;
    } else {
        cout << "Informacao sobre ensino medio invalida";
        return 0;
    }

    if (temDireito) cout << "Voce terah direito a isencao";
    else cout << "Infelizmente voce nao tem direito a isencao";

    return 0;
}