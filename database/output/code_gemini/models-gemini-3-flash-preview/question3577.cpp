/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long tx, ty;
    if (!(cin >> tx >> ty)) return 0;

    long long n;
    if (!(cin >> n)) return 0;

    long long cC = 0, cB = 0, cE = 0, cD = 0;
    for (long long i = 0; i < n; ++i) {
        char c;
        if (!(cin >> c)) break;
        if (c == 'C') {
            cC++;
        } else if (c == 'B') {
            cB++;
        } else if (c == 'E') {
            cE++;
        } else if (c == 'D') {
            cD++;
        }
    }

    bool okX = (tx >= -cD && tx <= cE);
    bool okY = (ty >= -cC && ty <= cB);

    if (okX && okY) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}