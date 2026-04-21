/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r;
    if (!(cin >> r)) return 0;
    if (r <= 0) return 0;

    int n = 2 * r - 1;
    for (int i = 1; i <= n; ++i) {
        int stars = (i <= r) ? i : (2 * r - i);
        int pad = r - stars;

        for (int j = 0; j < pad; ++j) {
            cout << '.';
        }
        
        int row_width = 2 * stars - 1;
        for (int j = 1; j <= row_width; ++j) {
            if (j % 2 == 1) {
                cout << '*';
            } else {
                cout << '.';
            }
        }

        for (int j = 0; j < pad; ++j) {
            cout << '.';
        }
        cout << '\n';
    }

    return 0;
}