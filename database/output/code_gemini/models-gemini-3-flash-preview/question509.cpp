/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x, y;
    if (!(cin >> x >> y)) return 0;

    cout << (x > y) << "\n";
    cout << (x == y) << "\n";
    cout << (x < y) << "\n";
    cout << (x != y) << "\n";
    cout << (x >= y) << "\n";
    cout << (x <= y) << "\n";

    return 0;
}