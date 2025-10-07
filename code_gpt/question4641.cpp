/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;

    int totalMinutes = m1 + m2;
    int totalHours = h1 + h2 + totalMinutes / 60;
    totalMinutes = totalMinutes % 60;
    totalHours = totalHours % 24;

    cout << "Terminarei meu treino por volta das " << totalHours << " horas e " << totalMinutes << " minutos!" << endl;

    return 0;
}
