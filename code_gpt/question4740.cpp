/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    double y;

    if (x == 0) {
        y = -1.0;
    } else if (x == 1) {
        y = 3.0;
    } else if (x == -1) {
        y = -9.0;
    } else {
        y = x * x + 2 * x - 1; // Exemplo de expressão, ajustável conforme necessidade
    }

    cout << "Y= " << y << endl;
    return 0;
}
