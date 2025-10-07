/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void piramideNumerica(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << i << (j == i ? "" : " ");
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    piramideNumerica(n);
    return 0;
}
