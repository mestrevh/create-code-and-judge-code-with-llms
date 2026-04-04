/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    if (a == b && b == c) {
        cout << 1 << "\n";
    } else if (a != b && b != c && a != c) {
        cout << 2 << "\n";
    } else {
        cout << 3 << "\n";
    }

    return 0;
}