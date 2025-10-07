/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int A, L, P, H;
    cin >> A >> L >> P >> H;
    
    int aDiamonds = A * H;
    int lDiamonds = L * H;
    int pDiamonds = P * H;

    int maxAL = (aDiamonds + lDiamonds + abs(aDiamonds - lDiamonds)) / 2;
    int maxDiamonds = (maxAL + pDiamonds + abs(maxAL - pDiamonds)) / 2;

    cout << maxDiamonds << endl;
    return 0;
}
