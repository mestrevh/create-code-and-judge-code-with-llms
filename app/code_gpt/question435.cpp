/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int minutosPorProcesso;
    cin >> minutosPorProcesso;
    int horasPorDia = 8;
    int minutosPorHora = 60;
    int totalMinutos = horasPorDia * minutosPorHora;
    int totalProcessos = totalMinutos / minutosPorProcesso;
    cout << totalProcessos << endl;
    return 0;
}
