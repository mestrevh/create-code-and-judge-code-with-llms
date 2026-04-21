/*
Código criado pelo models/gemini-3.1-pro-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int test_case = 1;
    while (cin >> n && n != 0) {
        int max_x = -20000, min_y = 20000, min_u = 20000, max_v = -20000;
        for (int i = 0; i < n; ++i) {
            int x, y, u, v;
            cin >> x >> y >> u >> v;
            if (x > max_x) max_x = x;
            if (y < min_y) min_y = y;
            if (u < min_u) min_u = u;
            if (v > max_v) max_v = v;
        }

        cout << "Teste " << test_case++ << "\n";
        if (max_x < min_u && min_y > max_v) {
            cout << max_x << " " << min_y << " " << min_u << " " << max_v << "\n\n";
        } else {
            cout << "nenhum\n\n";
        }
    }

    return 0;
}