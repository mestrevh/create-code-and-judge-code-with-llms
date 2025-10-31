/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

bool isTriangular(int n, int &a, int &b, int &c) {
    for (int i = 1; i <= n / 3; ++i) {
        if (i * (i + 1) * (i + 2) == n) {
            a = i; b = i + 1; c = i + 2;
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    if (n < 0) {
        cout << "Falso" << endl;
        return 0;
    }

    int a, b, c;
    if (isTriangular(n, a, b, c)) {
        cout << a << " * " << b << " * " << c << " = " << n << endl;
        cout << "Verdadeiro" << endl;
    } else {
        cout << "Falso" << endl;
    }
    return 0;
}
