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

    long long n;
    if (!(cin >> n)) return 0;

    long long x0, x1, y0, y1, z0, z1;
    if (!(cin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1)) return 0;

    long long x_start = max(x0, n - y1 - z1);
    long long x_end = min(x1, n - y0 - z0);

    if (x_start <= x_end) {
        long long x = x_start;
        long long S = n - x;
        long long z_low = max(z0, S - y1);
        long long z = z_low;
        long long y = S - z;

        cout << "S" << "\n";
        cout << x << " " << y << " " << z << "\n";
    } else {
        cout << "N" << "\n";
    }

    return 0;
}