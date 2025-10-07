/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

#define TROCA(x, y) { int temp = x; x = y; y = temp; }

int main() {
    int a, b;
    cin >> a >> b;

    cout << "a: " << a << " b: " << b << endl;
    TROCA(a, b);
    cout << "a: " << a << " b: " << b << endl;

    return 0;
}
