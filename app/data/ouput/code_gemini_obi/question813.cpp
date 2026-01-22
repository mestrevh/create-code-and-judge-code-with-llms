/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

int main() {
    int n, test = 1;
    while (cin >> n && n != 0) {
        int ix1 = -10001, iy1 = -10001, ix2 = 10001, iy2 = 10001;
        for (int i = 0; i < n; ++i) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int rleft = min(x1, x2), rtop = max(y1, y2), rright = max(x1, x2), rbot = min(y1, y2);
            // Update intersection
            ix1 = max(ix1, rleft);
            iy1 = min(iy1, rtop);
            ix2 = min(ix2, rright);
            iy2 = max(iy2, rbot);
        }
        cout << "Teste " << test++ << endl;
        if (ix1 <= ix2 && iy2 <= iy1) {
            cout << ix1 << ' ' << iy1 << ' ' << ix2 << ' ' << iy2 << endl;
        } else {
            cout << "nenhum" << endl;
        }
        cout << endl;
    }
    return 0;
}
