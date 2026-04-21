/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long idade;
    if (!(cin >> idade)) return 0;

    string resp;
    if (idade <= 2) resp = "O individuo eh um Bebe Jovem Menor de Idade.";
    else if (idade <= 12) resp = "O individuo eh uma Crianca Jovem Menor de Idade.";
    else if (idade <= 18) resp = "O individuo eh um Adolescente Jovem Menor de Idade.";
    else if (idade <= 19) resp = "O individuo eh um Jovem Maior de Idade.";
    else if (idade <= 45) resp = "O individuo eh um Adulto Maior de Idade.";
    else if (idade <= 60) resp = "O individuo eh um Adulto de Meia Idade Maior de Idade.";
    else if (idade < 75) resp = "O individuo eh um Idoso Maior de Idade.";
    else if (idade <= 90) resp = "O individuo eh um Idoso Ansiao Maior de Idade.";
    else resp = "O individuo eh um Idoso na Velhice Extrema Maior de Idade.";

    cout << resp;
    return 0;
}