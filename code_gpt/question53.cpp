/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double k;
    while (cin >> k, k != -1) {
        double sum = 0.0;
        int n = 0;
        while (sum <= log(k)) {
            n++;
            sum += 1.0 / n;
        }
        cout << n << endl;
    }
    return 0;
}
