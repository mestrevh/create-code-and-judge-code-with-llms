/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (cin >> n >> m) {
        if (m < 1) {
            for (int i = 1; i <= n; ++i) {
                cout << setw(3) << i << "\n";
            }
        } else {
            for (int i = 1; i <= n; ++i) {
                cout << setw(3) << i;
                if (i % m == 0 || i == n) {
                    cout << "\n";
                }
            }
        }
    }

    return 0;
}