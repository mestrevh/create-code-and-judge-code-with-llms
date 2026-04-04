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
    char sep;
    if (!(cin >> n >> sep >> m)) return 0;

    if (m % 2 == 0) {
        cout << "Nao posso construir nessas proporcoes" << endl;
        return 0;
    }

    long long masonry_count = 0;
    long long window_count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            if (i >= n - 2) {
                if (j == m / 2) {
                    c = 'H';
                } else {
                    c = '=';
                    masonry_count++;
                }
            } else {
                int dist_from_bottom = n - 1 - i;
                if (dist_from_bottom % 2 == 0) {
                    if (j % 2 == 1) {
                        c = 'o';
                        window_count++;
                    } else {
                        c = '=';
                        masonry_count++;
                    }
                } else {
                    c = '=';
                    masonry_count++;
                }
            }
            cout << c;
            if (j < m - 1) cout << ' ';
        }
        cout << '\n';
    }

    long long foundation_len = 2LL * m - 1;
    for (int i = 0; i < foundation_len; ++i) {
        cout << '-';
    }

    long long total_cost = 500LL + (foundation_len * 133LL) + (masonry_count * 85LL) + (window_count * 250LL);
    cout << "\n\nE o valor total eh " << total_cost << endl;

    return 0;
}