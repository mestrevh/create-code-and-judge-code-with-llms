/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 3) {
        cout << 0 << endl;
    } else {
        int diagonais = (n * (n - 3)) / 2;
        cout << diagonais << endl;
    }
    return 0;
}
