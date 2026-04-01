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
    int case_num = 1;
    while (cin >> n >> m) {
        vector<long long> a(n + 1);
        for (int i = 0; i <= n; ++i) {
            cin >> a[i];
        }

        vector<long long> b(m + 1);
        for (int i = 0; i <= m; ++i) {
            cin >> b[i];
        }

        vector<long long> c(n + m + 1, 0);
        for (int i = 0; i <= n; ++i) {
            if (a[i] == 0) continue;
            for (int j = 0; j <= m; ++j) {
                c[i + j] += a[i] * b[j];
            }
        }

        cout << "Caso #" << case_num++ << ":";
        for (int i = 0; i <= n + m; ++i) {
            cout << " " << c[i];
        }
        cout << "\n";
    }

    return 0;
}