/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, test = 1;
    while (cin >> N, N) {
        int x1 = -10001, y1 = -10001, x2 = 10001, y2 = 10001;

        for (int i = 0; i < N; ++i) {
            int X, Y, U, V;
            cin >> X >> Y >> U >> V;

            int rx1 = min(X, U), rx2 = max(X, U);
            int ry1 = max(Y, V), ry2 = min(Y, V);

            x1 = max(x1, rx1);
            x2 = min(x2, rx2);
            y1 = min(y1, ry1);
            y2 = max(y2, ry2);
        }

        cout << "Teste " << test++ << '\n';
        if (x1 > x2 || y2 > y1)
            cout << "nenhum\n";
        else
            cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        cout << '\n';
    }
    return 0;
}
