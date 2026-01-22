/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && b == c) {
        cout << 1 << endl;
    } else if (a != b && a != c && b != c) {
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }

    return 0;
}
