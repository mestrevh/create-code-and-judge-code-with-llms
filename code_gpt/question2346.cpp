/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void contagemRegressiva(int n) {
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << i;
            if (j < i - 1) cout << "-";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    contagemRegressiva(n);
    return 0;
}
