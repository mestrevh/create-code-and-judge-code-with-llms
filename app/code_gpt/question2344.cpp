/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void fibonacci(int n) {
    int a = 0, b = 1, c;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cout << b << endl;
            continue;
        }
        c = a + b;
        cout << c << endl;
        a = b;
        b = c;
    }
}

int main() {
    int n;
    cin >> n;
    fibonacci(n);
    return 0;
}
