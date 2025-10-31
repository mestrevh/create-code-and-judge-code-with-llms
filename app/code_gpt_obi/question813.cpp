/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, caso = 1;
    while (cin >> N, N != 0) {
        int ix1, iy1, ix2, iy2;
        for (int i = 0; i < N; ++i) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int rx1 = min(x1, x2);
            int ry1 = max(y1, y2);
            int rx2 = max(x1, x2);
            int ry2 = min(y1, y2);
            if (i == 0) {
                ix1 = rx1;
                iy1 = ry1;
                ix2 = rx2;
                iy2 = ry2;
            } else {
                ix1 = max(ix1, rx1);
                iy1 = min(iy1, ry1);
                ix2 = min(ix2, rx2);
                iy2 = max(iy2, ry2);
            }
        }
        cout << "Teste " << caso++ << endl;
        if (ix1 <= ix2 && iy2 <= iy1)
            cout << ix1 << " " << iy1 << " " << ix2 << " " << iy2 << endl;
        else
            cout << "nenhum" << endl;
        cout << endl;
    }
    return 0;
}
