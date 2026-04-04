/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x, y;
    if (!(cin >> x >> y)) return 0;

    if (x == 0 && y == 0) {
        cout << "origem\n";
    } else if (y == 0) {
        cout << "eixo x\n";
    } else if (x == 0) {
        cout << "eixo y\n";
    } else if (x > 0 && y > 0) {
        cout << "primeiro\n";
    } else if (x < 0 && y > 0) {
        cout << "segundo\n";
    } else if (x < 0 && y < 0) {
        cout << "terceiro\n";
    } else if (x > 0 && y < 0) {
        cout << "quarto\n";
    }

    return 0;
}