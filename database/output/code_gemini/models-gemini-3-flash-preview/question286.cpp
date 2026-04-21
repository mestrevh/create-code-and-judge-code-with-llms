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
    while (cin >> a >> b >> c) {
        if (a != b && a != c) {
            cout << "A\n";
        } else if (b != a && b != c) {
            cout << "B\n";
        } else if (c != a && c != b) {
            cout << "C\n";
        } else {
            cout << "*\n";
        }
    }

    return 0;
}