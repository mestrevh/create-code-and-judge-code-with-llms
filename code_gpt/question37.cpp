/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int horas = N / 3600;
    N %= 3600;
    int minutos = N / 60;
    int segundos = N % 60;

    cout << horas << " h " << minutos << " m " << segundos << " s" << endl;

    return 0;
}
