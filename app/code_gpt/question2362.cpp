/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int horas, minutos, segundos;
    cin >> horas >> minutos >> segundos;
    int totalSegundos = horas * 3600 + minutos * 60 + segundos;
    cout << totalSegundos << endl;
    return 0;
}
