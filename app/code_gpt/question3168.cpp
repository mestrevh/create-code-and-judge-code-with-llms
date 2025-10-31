/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int calcular(int a, int b, int c) {
    return (c > a) ? 2 * a : 3 * b;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << calcular(a, b, c) << endl;
    return 0;
}
