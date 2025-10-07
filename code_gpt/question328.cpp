/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    if (x == 0 && y == 0) {
        cout << "origem" << endl;
    } else if (x == 0) {
        cout << "eixo y" << endl;
    } else if (y == 0) {
        cout << "eixo x" << endl;
    } else if (x > 0 && y > 0) {
        cout << "primeiro" << endl;
    } else if (x < 0 && y > 0) {
        cout << "segundo" << endl;
    } else if (x < 0 && y < 0) {
        cout << "terceiro" << endl;
    } else {
        cout << "quarto" << endl;
    }

    return 0;
}
