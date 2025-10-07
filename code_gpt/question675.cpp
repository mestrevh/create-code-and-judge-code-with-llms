/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int x1, y1, x2, y2, S, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> S >> x3 >> y3;

    if (S == 0) {
        if (x3 < min(x1, x2)) cout << "S" << endl;
        else cout << "N" << endl;
    } else {
        if (x3 > max(x1, x2)) cout << "S" << endl;
        else cout << "N" << endl;
    }

    return 0;
}
