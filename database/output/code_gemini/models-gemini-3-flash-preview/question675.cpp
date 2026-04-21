/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long x1, y1, x2, y2, s, x3, y3;
    while (cin >> x1 >> y1 >> x2 >> y2 >> s >> x3 >> y3) {
        bool possible = false;
        if (s == 0) {
            // Left to right movement: shoal must be to the left of the entire net.
            if (x3 < x1 && x3 < x2) {
                possible = true;
            }
        } else if (s == 1) {
            // Right to left movement: shoal must be to the right of the entire net.
            if (x3 > x1 && x3 > x2) {
                possible = true;
            }
        }
        if (possible) {
            cout << "S" << endl;
        } else {
            cout << "N" << endl;
        }
    }
    return 0;
}