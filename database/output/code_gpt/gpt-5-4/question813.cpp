/*
Código criado pelo gpt-5.4
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, teste = 1;
    while (cin >> N && N != 0) {
        int left = -1000000000, right = 1000000000;
        int top = 1000000000, bottom = -1000000000;

        for (int i = 0; i < N; ++i) {
            int X, Y, U, V;
            cin >> X >> Y >> U >> V;
            left = max(left, X);
            top = min(top, Y);
            right = min(right, U);
            bottom = max(bottom, V);
        }

        cout << "Teste " << teste++ << "\n";
        if (left <= right && bottom <= top) {
            cout << left << ' ' << top << ' ' << right << ' ' << bottom << "\n";
        } else {
            cout << "nenhum\n";
        }
        cout << "\n";
    }

    return 0;
}