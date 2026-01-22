/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

double mediaMaisMedia(double A, double B) {
    double media1 = (A + B) / 2.0;
    double media2 = (media1 + A) / 2.0;
    return (media2 + A) / 2.0;
}

int main() {
    double A, B;
    cin >> A >> B;
    cout << fixed << setprecision(2) << mediaMaisMedia(A, B) << endl;
    return 0;
}
