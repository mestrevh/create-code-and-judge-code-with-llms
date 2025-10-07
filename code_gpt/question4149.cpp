/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 2) {
        cout << "Valor invalido" << endl;
        return 0;
    }

    double f1 = 0, f2 = 1, fn;
    for (int i = 3; i <= n; ++i) {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }

    double golden_ratio = f2 / f1;
    cout << fixed << setprecision(15) << golden_ratio << endl;

    return 0;
}
