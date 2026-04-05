/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long bx;
    if (!(cin >> n >> bx)) return 0;

    long long x_val = 0;
    for (int i = 0; i < n; ++i) {
        long long d;
        cin >> d;
        x_val = x_val * bx + d;
    }

    int m;
    long long by;
    if (!(cin >> m >> by)) return 0;

    long long y_val = 0;
    for (int i = 0; i < m; ++i) {
        long long d;
        cin >> d;
        y_val = y_val * by + d;
    }

    if (x_val < y_val) {
        cout << "<\n";
    } else if (x_val > y_val) {
        cout << ">\n";
    } else {
        cout << "=\n";
    }

    return 0;
}