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

    int h = 0;
    int p = 0;
    int d = 1;

    for (int i = 0; i < n; ++i) {
        char cmd;
        if (!(cin >> cmd)) break;

        if (cmd == 'S') {
            if (h + 10 <= 200) {
                h += 10;
            }
        } else if (cmd == 'D') {
            if (h - 10 >= 0) {
                h -= 10;
            }
        } else if (cmd == 'F') {
            if (h > 0) {
                int next_p = p + d * 10;
                if (next_p >= -2000 && next_p <= 2000) {
                    p = next_p;
                }
            }
        } else if (cmd == 'V') {
            if (h > 0) {
                int next_p = p + d * 10;
                if (next_p >= -2000 && next_p <= 2000) {
                    p = next_p;
                }
                d *= -1;
            }
        }
    }

    int dist = (p < 0) ? -p : p;
    cout << h << " " << dist << endl;

    return 0;
}