/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        vector<string> grid(n);
        string dummy;
        getline(cin, dummy); // consume newline after m
        
        for (int i = 0; i < n; ++i) {
            getline(cin, grid[i]);
        }

        int a, b;
        cin >> a >> b;

        int ry = a / n;
        int rx = b / m;

        for (int i = 0; i < n; ++i) {
            for (int r = 0; r < ry; ++r) {
                for (int j = 0; j < m; ++j) {
                    for (int c = 0; c < rx; ++c) {
                        cout << grid[i][j];
                    }
                }
                cout << "\n";
            }
        }
        cout << "\n";
    }

    return 0;
}

