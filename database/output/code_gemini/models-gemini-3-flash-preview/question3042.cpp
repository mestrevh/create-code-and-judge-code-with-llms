/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    if (cin >> a >> b >> c) {
        if (a > b) {
            if (b <= c) {
                cout << ":)\n";
            } else {
                if (a - b > b - c) {
                    cout << ":)\n";
                } else {
                    cout << ":(\n";
                }
            }
        } else if (a < b) {
            if (b >= c) {
                cout << ":(\n";
            } else {
                if (c - b >= b - a) {
                    cout << ":)\n";
                } else {
                    cout << ":(\n";
                }
            }
        } else {
            if (c > b) {
                cout << ":)\n";
            } else {
                cout << ":(\n";
            }
        }
    }

    return 0;
}