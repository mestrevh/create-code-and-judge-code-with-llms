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

    long long x1, y1, x2, y2;
    if (!(cin >> x1 >> y1 >> x2 >> y2)) return 0;

    double da = (double)(y1 - y2);
    double db = (double)(x2 - x1);
    double dc = (double)((long double)x1 * y2 - (long double)x2 * y1);

    if (db != 0) {
        da /= db;
        dc /= db;
        db = 1.0;
    } else if (da != 0) {
        dc /= da;
        db = 0.0;
        da = 1.0;
    }

    if (da == 0.0) da = 0.0;
    if (db == 0.0) db = 0.0;
    if (dc == 0.0) dc = 0.0;

    cout << fixed << setprecision(2);
    cout << "(" << da << "x) + (" << db << "y) + (" << dc << ") = 0" << endl;

    return 0;
}