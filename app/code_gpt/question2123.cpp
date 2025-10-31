/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

bool podeComprar(int C, int M, int P) {
    if (C == 0) return true;
    if (M < P) return false;
    return podeComprar(C - 1, M - P, P);
}

int main() {
    int C, M, P;
    while (cin >> C >> M >> P) {
        if (podeComprar(C, M, P)) cout << "Sim" << endl;
        else cout << "Nao" << endl;
    }
    return 0;
}
