/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int calcularIdadeHumana(int idade, string porte) {
    if (porte == "pequeno") {
        if (idade == 1) return 5;
        if (idade == 2) return 10;
        if (idade == 3) return 15;
        if (idade == 4) return 20;
        return 20 + (idade - 4) * 4;
    } else if (porte == "medio") {
        if (idade == 1) return 6;
        if (idade == 2) return 12;
        if (idade == 3) return 18;
        if (idade == 4) return 24;
        return 24 + (idade - 4) * 5;
    } else { // grande
        if (idade == 1) return 7;
        if (idade == 2) return 14;
        if (idade == 3) return 21;
        if (idade == 4) return 28;
        return 28 + (idade - 4) * 6;
    }
}

int main() {
    int idade;
    string porte;
    cin >> idade >> porte;
    cout << calcularIdadeHumana(idade, porte) << endl;
    return 0;
}
