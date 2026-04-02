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

    int n;
    if (cin >> n) {
        for (int i = 0; i < n; ++i) {
            double x, y;
            if (cin >> x >> y) {
                double val = 1.0;
                for (int j = 0; j < n; ++j) {
                    if (j > 0) {
                        cout << " ";
                    }
                    cout << fixed << setprecision(2) << val;
                    val *= x;
                }
                cout << "\n";
            }
        }
    }

    return 0;
}