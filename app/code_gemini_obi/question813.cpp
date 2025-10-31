/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, test_num = 1;
    while (cin >> N && N != 0) {
        int l = -10001, t = -10001, r = 10001, b = 10001; // l=x esq, t=y sup, r=x dir, b=y inf
        for (int i = 0; i < N; ++i) {
            int X, Y, U, V;
            cin >> X >> Y >> U >> V;
            int x1 = min(X, U), x2 = max(X, U);
            int y1 = max(Y, V), y2 = min(Y, V); // y cresce pra cima: maior Y é em cima
            l = max(l, x1);
            r = min(r, x2);
            t = max(t, y2);
            b = min(b, y1);
        }
        cout << "Teste " << test_num++ << endl;
        if (l <= r && t <= b) {
            cout << l << ' ' << b << ' ' << r << ' ' << t << endl;
        } else {
            cout << "nenhum" << endl;
        }
        cout << endl;
    }
    return 0;
}
