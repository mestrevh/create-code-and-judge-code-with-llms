/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

#define SWAP(x, y) { int tmp = x; x = y; y = tmp; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    if (cin >> a >> b) {
        cout << "a: " << a << " b: " << b << "\n";
        SWAP(a, b);
        cout << "a: " << a << " b: " << b << "\n";
    }

    return 0;
}