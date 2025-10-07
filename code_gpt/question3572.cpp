/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int dias;
    cin >> dias;

    int anos = dias / 365;
    dias %= 365;
    int semanas = dias / 7;
    dias %= 7;

    cout << anos << " ano(s), " << semanas << " semana(s) e " << dias << " dia(s)" << endl;

    return 0;
}
