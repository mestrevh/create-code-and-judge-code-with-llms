/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double N;
    cin >> N;

    double entrada = (N - 2 * (N / 3 - 0.01)) < 0 ? 0 : (N - (N / 3) * 2);
    double prestacao = (N - entrada) / 2;

    cout << fixed << setprecision(2) << entrada << endl;
    cout << fixed << setprecision(2) << prestacao << endl;
    cout << fixed << setprecision(2) << prestacao << endl;

    return 0;
}
