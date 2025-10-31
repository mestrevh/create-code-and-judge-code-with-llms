/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    long long segundos;
    cin >> segundos;

    long long dias = segundos / 86400;
    segundos %= 86400;
    long long horas = segundos / 3600;
    segundos %= 3600;
    long long minutos = segundos / 60;
    long long secs = segundos % 60;

    cout << dias << endl;
    cout << horas << endl;
    cout << minutos << endl;
    cout << secs << endl;

    return 0;
}
