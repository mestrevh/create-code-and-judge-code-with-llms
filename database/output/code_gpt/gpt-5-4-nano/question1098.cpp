/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int idade;
    if (!(cin >> idade)) return 0;

    string categoria;
    if (idade >= 5 && idade <= 7) categoria = "Infantil A";
    else if (idade >= 8 && idade <= 10) categoria = "Infantil B";
    else if (idade >= 11 && idade <= 13) categoria = "Juvenil A";
    else if (idade >= 14 && idade <= 17) categoria = "Juvenil B";
    else if (idade >= 18 && idade <= 40) categoria = "Adulto";
    else if (idade >= 41) categoria = "Master";
    else categoria = "Idade invalida.";

    cout << categoria;
    return 0;
}