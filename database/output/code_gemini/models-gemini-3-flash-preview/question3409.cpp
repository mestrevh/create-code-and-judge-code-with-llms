/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double x, y, x1, y1, x2, y2;

    if (cin >> x >> y >> x1 >> y1 >> x2 >> y2) {
        if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
            cout << "Dentro\n";
        } else {
            cout << "Fora\n";
        }
    }

    return 0;
}