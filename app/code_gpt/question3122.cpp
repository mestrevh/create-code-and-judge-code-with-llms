/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int D, C;
    cin >> D >> C;
    int ticksPorDia = 12000;
    int totalTicks = D * (ticksPorDia / 2);
    int ticksPorCasa = totalTicks / C;
    cout << ticksPorCasa << endl;
    return 0;
}
