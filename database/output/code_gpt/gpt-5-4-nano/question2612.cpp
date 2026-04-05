/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string ensino;
    if (!(cin >> ensino)) return 0;

    char encceja;
    cin >> encceja;

    int nota;
    cin >> nota;

    string escola;
    cin >> escola;

    double renda;
    cin >> renda;

    char isenc2018;
    cin >> isenc2018;

    bool direito = false;
    bool ensinoValido = (ensino == "CLD" || ensino == "CVC" || ensino == "CSC" || ensino == "NCC");
    if (!ensinoValido) {
        cout << "Informacao sobre ensino medio invalida";
        return 0;
    }

    bool enccejaFez = (encceja == 's' || encceja == 'n');
    if (!enccejaFez) {
        cout << "Infelizmente voce nao tem direito a isencao";
        return 0;
    }

    bool enccejaPerfil = false;
    if (encceja == 's') enccejaPerfil = (nota >= 400 && nota <= 800);
    else enccejaPerfil = false;

    bool perfil1 = false;
    if (ensino == "CVC") perfil1 = true;

    bool perfil3 = false;
    if (ensino == "CLD") {
        if (escola == "PUB" || escola == "PSB") perfil3 = true;
        else if (escola == "PCB") perfil3 = (renda <= 1431.0);
        else if (escola == "PPS" || escola == "PPB") perfil3 = (renda <= 1431.0);
        else if (escola == "PPB") perfil3 = (renda <= 1431.0);
        else if (escola == "PPB") perfil3 = (renda <= 1431.0);
    }

    bool perfil2 = enccejaPerfil;

    if (perfil1 || perfil2 || perfil3) direito = true;

    cout << (direito ? "Você terah direito a isencao" : "Infelizmente voce nao tem direito a isencao");
    return 0;
}