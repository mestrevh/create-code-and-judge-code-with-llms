/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int T, A, B, C, D, E, correct = 0;
    cin >> T;
    cin >> A >> B >> C >> D >> E;
    if (A == T) correct++;
    if (B == T) correct++;
    if (C == T) correct++;
    if (D == T) correct++;
    if (E == T) correct++;
    cout << correct << endl;
    return 0;
}
