/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, test_count = 1;
    while (cin >> n && n != 0) {
        int x_max = -10001;
        int y_min = 10001;
        int u_min = 10001;
        int v_max = -10001;

        for (int i = 0; i < n; ++i) {
            int x, y, u, v;
            cin >> x >> y >> u >> v;
            
            if (x > x_max) x_max = x;
            if (y < y_min) y_min = y;
            if (u < u_min) u_min = u;
            if (v > v_max) v_max = v;
        }

        cout << "Teste " << test_count++ << "\n";
        if (x_max < u_min && v_max < y_min) {
            cout << x_max << " " << y_min << " " << u_min << " " << v_max << "\n\n";
        } else {
            cout << "nenhum\n\n";
        }
    }

    return 0;
}