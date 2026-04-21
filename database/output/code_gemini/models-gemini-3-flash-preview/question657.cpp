/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    while (cin >> k && k != 0) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < k; ++i) {
            int x, y;
            cin >> x >> y;
            if (x == n || y == m) {
                cout << "divisa\n";
            } else if (x > n && y > m) {
                cout << "NE\n";
            } else if (x < n && y > m) {
                cout << "NO\n";
            } else if (x > n && y < m) {
                cout << "SE\n";
            } else if (x < n && y < m) {
                cout << "SO\n";
            }
        }
    }

    return 0;
}