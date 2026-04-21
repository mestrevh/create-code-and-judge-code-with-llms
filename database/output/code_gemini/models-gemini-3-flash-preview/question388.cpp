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

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        pos[i] = m;
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            if (x != 0 && pos[i] == m) {
                pos[i] = j;
            }
        }
    }

    bool ok = true;
    for (int i = 0; i < n - 1; ++i) {
        if (pos[i] == m) {
            if (pos[i + 1] != m) {
                ok = false;
                break;
            }
        } else {
            if (pos[i + 1] <= pos[i]) {
                ok = false;
                break;
            }
        }
    }

    if (ok) {
        cout << 'S';
    } else {
        cout << 'N';
    }

    return 0;
}