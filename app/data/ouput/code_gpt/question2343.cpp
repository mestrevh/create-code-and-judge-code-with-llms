/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void exibeMultiplos(int i, int f, int x) {
    for (int j = i; j <= f; j++) {
        if (j % x == 0) {
            cout << j << endl;
        }
    }
}

int main() {
    int i, f, x;
    cin >> i >> f >> x;
    exibeMultiplos(i, f, x);
    return 0;
}
