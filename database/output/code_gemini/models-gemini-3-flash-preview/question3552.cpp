/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    if (cin >> x >> y) {
        if (x <= y) {
            for (int i = x; i <= y; ++i) {
                cout << i << "\n";
            }
        } else {
            for (int i = x; i >= y; --i) {
                cout << i << "\n";
            }
        }
    }

    return 0;
}