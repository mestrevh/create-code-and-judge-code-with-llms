/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    string s;
    if (!(cin >> s)) return 0;

    string ss = s + s + s;
    int max_beads = 0;

    for (int i = n; i < 2 * n; ++i) {
        int cr = 0;
        char tr = 'w';
        for (int k = 0; k < n; ++k) {
            char curr = ss[i + k];
            if (tr == 'w') {
                tr = curr;
            }
            if (curr != 'w' && curr != tr) {
                break;
            }
            cr++;
        }

        int cl = 0;
        char tl = 'w';
        for (int k = 0; k < n - cr; ++k) {
            char curr = ss[i - 1 - k];
            if (tl == 'w') {
                tl = curr;
            }
            if (curr != 'w' && curr != tl) {
                break;
            }
            cl++;
        }

        if (cr + cl > max_beads) {
            max_beads = cr + cl;
        }
    }

    cout << max_beads << endl;

    return 0;
}