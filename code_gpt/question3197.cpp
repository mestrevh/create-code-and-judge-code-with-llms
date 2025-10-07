/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int garrafas2L, garrafas600ml, latas350ml;
    cin >> garrafas2L >> garrafas600ml >> latas350ml;

    double totalLitros = garrafas2L * 2 + garrafas600ml * 0.6 + latas350ml * 0.35;
    cout << totalLitros << endl;

    return 0;
}
