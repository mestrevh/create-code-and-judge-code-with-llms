/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int L, C;
    cin >> L >> C;
    int tipo1 = (L - 1) * (C - 1) + ((L % 2 == 0 || C % 2 == 0) ? 0 : 1);
    tipo1 += (L - 1) + (C - 1);
    tipo1 = L * C - L - C + 1;

    int tipo2 = 2 * (L + C - 2);
    cout << tipo1 << endl << tipo2 << endl;
    return 0;
}
`