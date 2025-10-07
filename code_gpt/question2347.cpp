/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void contagemProgressiva(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i;
            if (j < i) cout << "-";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    contagemProgressiva(n);
    return 0;
}
