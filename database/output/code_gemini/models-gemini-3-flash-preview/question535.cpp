/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    for (int t = 1; t <= N; ++t) {
        int l, i;
        if (!(cin >> l >> i)) break;

        cout << "Caso " << t << ":\n";

        int u = (l - 2) - i;
        int width = 2 * l;

        for (int r = 0; r < 2 * l; ++r) {
            if (r == 0 || r == 2 * l - 1) {
                for (int j = 0; j <= width; ++j) {
                    if (j == 0 || j == 1 || j == width - 1 || j == width || (j > 1 && j < width - 1 && j % 2 == 1)) {
                        cout << '*';
                    } else {
                        cout << ' ';
                    }
                }
            } else if (r < l - 1) {
                int s1 = r + 1;
                int s2 = width - (r + 1);
                bool sand = (r >= l - 1 - u);
                for (int j = 0; j <= width; ++j) {
                    if (j == 0 || j == s1 || j == s2 || j == width) {
                        cout << '*';
                    } else if (sand && j > s1 && j < s2) {
                        cout << '.';
                    } else {
                        cout << ' ';
                    }
                }
            } else if (r == l - 1 || r == l) {
                for (int j = 0; j <= width; ++j) {
                    if (j == 0 || j == l || j == width) {
                        cout << '*';
                    } else {
                        cout << ' ';
                    }
                }
            } else {
                int s1 = width - r;
                int s2 = r;
                bool sand = (r >= 2 * l - 1 - i);
                for (int j = 0; j <= width; ++j) {
                    if (j == 0 || j == s1 || j == s2 || j == width) {
                        cout << '*';
                    } else if (sand && j > s1 && j < s2) {
                        cout << '.';
                    } else {
                        cout << ' ';
                    }
                }
            }
            cout << '\n';
        }
    }

    return 0;
}