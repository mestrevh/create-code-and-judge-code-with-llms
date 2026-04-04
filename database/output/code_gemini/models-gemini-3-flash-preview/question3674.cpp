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

    long long a, b, c, d;
    if (!(cin >> a >> b >> c >> d)) return 0;

    if (a < 0 || b < 0 || c < 0 || d < 0) {
        cout << "lurn maf :(" << endl;
        return 0;
    }

    long long w = 0;
    if (a == 0) {
        w = b * b;
    }

    long long x = 0;
    if (w > 0) {
        x = 2;
    }

    long long y = 0;
    if (b + x > c) {
        if (w > c) {
            y = w - c;
        } else {
            y = 0;
        }
    } else {
        y = 0;
    }

    long long z = 0;
    if (y > 0) {
        if (d < 2000) {
            z = 2000 - d;
        } else {
            z = 0;
        }
    } else {
        z = 500;
    }

    cout << w << " laranjas" << "\n";
    cout << x << " bananas" << "\n";
    cout << y << " ovos" << "\n";
    cout << z << " mL de leite" << "\n";

    return 0;
}