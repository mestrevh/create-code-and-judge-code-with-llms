/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void printDiamond(int r) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < r - i - 1; ++j) cout << ".";
        for (int j = 0; j < i * 2 + 1; ++j) cout << (j % 2 == 0 ? "*" : ".");
        cout << endl;
    }
    for (int i = r - 2; i >= 0; --i) {
        for (int j = 0; j < r - i - 1; ++j) cout << ".";
        for (int j = 0; j < i * 2 + 1; ++j) cout << (j % 2 == 0 ? "*" : ".");
        cout << endl;
    }
}

int main() {
    int r;
    cin >> r;
    printDiamond(r);
    return 0;
}
