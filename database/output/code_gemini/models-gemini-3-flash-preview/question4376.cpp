/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 1; i <= n; ++i) {
        for (int s = 0; s < n - i; ++s) {
            cout << ' ';
        }
        for (int x = 0; x < 2 * i; ++x) {
            cout << 'X';
        }
        cout << '\n';
    }

    int trunk_h = n / 2;
    for (int i = 0; i < trunk_h; ++i) {
        for (int s = 0; s < n - 1; ++s) {
            cout << ' ';
        }
        cout << "XX\n";
    }

    return 0;
}