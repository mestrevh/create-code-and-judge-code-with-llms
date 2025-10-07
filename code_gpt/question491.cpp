/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int minutos, segundos;
    int totalSegundos = 0;

    for (int i = 0; i < 5; i++) {
        cin >> minutos >> segundos;
        totalSegundos += minutos * 60 + segundos;
    }

    int horas = totalSegundos / 3600;
    totalSegundos %= 3600;
    minutos = totalSegundos / 60;
    segundos = totalSegundos % 60;

    cout << horas << endl << minutos << endl << segundos << endl;

    return 0;
}
