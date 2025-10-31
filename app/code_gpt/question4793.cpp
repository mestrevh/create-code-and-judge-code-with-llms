/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double A, B, C, D;
    cin >> A >> B >> C >> D;

    double resultado_matematica1 = A * B + C / D;
    double resultado_matematica2 = (A * B) + (C / D);

    cout << fixed << setprecision(2) << resultado_matematica1 << endl;
    cout << fixed << setprecision(2) << A * B + C / D << endl;

    return 0;
}
