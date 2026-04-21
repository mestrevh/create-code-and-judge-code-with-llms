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
    while (cin >> a >> b >> c >> d) {
        long long area1 = a * b;
        long long area2 = c * d;
        if (area1 > area2) {
            cout << area1 << "\n";
        } else {
            cout << area2 << "\n";
        }
    }

    return 0;
}