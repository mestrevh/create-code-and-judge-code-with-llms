/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2 && (x1 != 0 || y1 != 0 || x2 != 0 || y2 != 0)) {
        int dx = abs(x1 - x2);
        int dy = abs(y1 - y2);

        if (dx == 0 && dy == 0) {
            cout << "0\n";
        } else if (dx == 0 || dy == 0 || dx == dy) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }

    return 0;
}