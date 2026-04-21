/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, y;
    if (!(cin >> m >> y)) return 0;

    if (m == 2) {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
            cout << 29 << "\n";
        } else {
            cout << 28 << "\n";
        }
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        cout << 30 << "\n";
    } else {
        cout << 31 << "\n";
    }

    return 0;
}