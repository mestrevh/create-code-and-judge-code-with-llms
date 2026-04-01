/*
Código criado pelo gpt-4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

int main() {
    int testCase = 1;
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        int x1 = -10000, y1 = -10000, x2 = 10000, y2 = 10000;

        for (int i = 0; i < N; ++i) {
            int X, Y, U, V;
            cin >> X >> Y >> U >> V;

            x1 = max(x1, X);
            y1 = max(y1, V);
            x2 = min(x2, U);
            y2 = min(y2, Y);
        }

        cout << "Teste " << testCase++ << endl;
        if (x1 < x2 && y1 < y2) {
            cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        } else {
            cout << "nenhum" << endl;
        }
        cout << endl;
    }
    return 0;
}