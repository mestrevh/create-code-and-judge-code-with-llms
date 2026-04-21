/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int p[7];

int find_p(int i) {
    if (p[i] == i) return i;
    return p[i] = find_p(p[i]);
}

void unite_p(int i, int j) {
    int ri = find_p(i);
    int rj = find_p(j);
    if (ri != rj) p[ri] = rj;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t = 1;
    while (cin >> n && n != 0) {
        for (int i = 0; i < 7; ++i) {
            p[i] = i;
        }

        int deg[7] = {0};
        bool active[7] = {false};

        for (int i = 0; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            if (u >= 0 && u <= 6 && v >= 0 && v <= 6) {
                deg[u]++;
                deg[v]++;
                active[u] = active[v] = true;
                unite_p(u, v);
            }
        }

        int odd = 0;
        for (int i = 0; i < 7; ++i) {
            if (deg[i] % 2 != 0) {
                odd++;
            }
        }

        int components = 0;
        int root = -1;
        for (int i = 0; i < 7; ++i) {
            if (active[i]) {
                int r = find_p(i);
                if (root == -1) {
                    root = r;
                    components = 1;
                } else if (r != root) {
                    components++;
                }
            }
        }

        cout << "Teste " << t++ << "\n";
        if (odd <= 2 && (n == 0 || components <= 1)) {
            cout << "sim\n\n";
        } else {
            cout << "nao\n\n";
        }
    }

    return 0;
}