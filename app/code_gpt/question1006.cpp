/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int x;
    while (cin >> x && x != 0) {
        int a = (x + 1) / 2;
        int b = a - 1;
        cout << a * a << " - " << b * b << endl;
    }
    return 0;
}
