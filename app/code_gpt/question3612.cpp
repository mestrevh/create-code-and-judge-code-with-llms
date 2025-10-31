/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void printColumn(int totalCadeiras, int cadeirasPorLinha, int coluna, int current = coluna) {
    if (current > totalCadeiras) return;
    cout << current << endl;
    printColumn(totalCadeiras, cadeirasPorLinha, coluna, current + cadeirasPorLinha);
}

int main() {
    int totalCadeiras, cadeirasPorLinha, coluna;
    cin >> totalCadeiras >> cadeirasPorLinha >> coluna;
    printColumn(totalCadeiras, cadeirasPorLinha, coluna);
    return 0;
}
