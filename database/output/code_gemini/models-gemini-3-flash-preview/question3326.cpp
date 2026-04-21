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
    if (!(cin >> a >> b >> c)) return 0;

    if (a < 0 || b < 0 || c < 0) {
        cout << "esses dados nao valem" << endl;
    } else if (b > a) {
        if (c <= b) {
            cout << ":(" << endl;
        } else if ((c - b) < (b - a)) {
            cout << ":(" << endl;
        } else {
            cout << ":)" << endl;
        }
    } else if (b < a) {
        if (c >= b) {
            cout << ":)" << endl;
        } else if ((b - c) >= (a - b)) {
            cout << ":(" << endl;
        } else {
            cout << ":)" << endl;
        }
    } else {
        if (c < b) {
            cout << ":(" << endl;
        } else {
            cout << ":)" << endl;
        }
    }

    return 0;
}