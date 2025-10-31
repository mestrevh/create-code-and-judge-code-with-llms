/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double media = (a + b + c + d) / 4;
    cout << fixed << setprecision(2);
    cout << "A media das alturas eh: " << media << endl;
    return 0;
}
