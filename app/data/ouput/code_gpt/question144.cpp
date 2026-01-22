/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

bool canFit(int W, int H, int w1, int h1, int w2, int h2) {
    return (w1 + w2 <= W && max(h1, h2) <= H) || (h1 + h2 <= H && max(w1, w2) <= W) ||
           (w1 + h2 <= W && max(h1, w2) <= H) || (h1 + w2 <= H && max(w1, h2) <= W) ||
           (h1 + w2 <= W && max(w1, h2) <= H) || (w1 + h2 <= H && max(h1, w2) <= W);
}

int main() {
    int X, Y, L1, H1, L2, H2;
    cin >> X >> Y >> L1 >> H1 >> L2 >> H2;

    if (canFit(X, Y, L1, H1, L2, H2)) {
        cout << 'S' << endl;
    } else {
        cout << 'N' << endl;
    }
    return 0;
}
