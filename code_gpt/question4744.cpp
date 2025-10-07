/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int latas, garrafas600, garrafas2l;
    cin >> latas >> garrafas600 >> garrafas2l;
    double totalLitros = latas * 0.35 + garrafas600 * 0.6 + garrafas2l * 2.0;
    cout << "Foram comprados " << totalLitros << " litros de refrigerante." << endl;
    return 0;
}
