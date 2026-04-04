/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    if (cin >> X >> Y) {
        for (int i = 1; i <= Y; ++i) {
            cout << i;
            if (i % X == 0 || i == Y) {
                cout << "\n";
            } else {
                cout << " ";
            }
        }
    }

    return 0;
}