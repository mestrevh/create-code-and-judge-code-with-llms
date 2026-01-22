/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a >= b && a >= c) cout << a << endl;
    if (b >= a && b >= c) cout << b << endl;
    if (c >= a && c >= b) cout << c << endl;
    if (a <= b && a <= c) cout << (b >= c ? c : b) << endl;
    if (b <= a && b <= c) cout << (a >= c ? c : a) << endl;
    if (c <= a && c <= b) cout << (a >= b ? b : a) << endl;
    return 0;
}
