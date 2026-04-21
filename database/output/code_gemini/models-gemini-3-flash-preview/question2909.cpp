/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (!(cin >> q)) return 0;
    while (q--) {
        int n;
        if (!(cin >> n)) break;
        vector<int> p(n);
        int pos1 = -1;
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            if (p[i] == 1) {
                pos1 = i;
            }
        }

        if (n == 0) continue;

        // Clockwise check: Student i+1 must be at (pos(i) + 1) % n
        bool cw = true;
        for (int i = 0; i < n; ++i) {
            if (p[(pos1 + i) % n] != i + 1) {
                cw = false;
                break;
            }
        }

        if (cw) {
            cout << "SIM, HORARIO" << endl;
            continue;
        }

        // Anti-clockwise check: Student i+1 must be at (pos(i) - 1 + n) % n
        bool acw = true;
        for (int i = 0; i < n; ++i) {
            if (p[(pos1 - i + n) % n] != i + 1) {
                acw = false;
                break;
            }
        }

        if (acw) {
            cout << "SIM, ANTI-HORARIO" << endl;
        } else {
            cout << "NAO" << endl;
        }
    }

    return 0;
}