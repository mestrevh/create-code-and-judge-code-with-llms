/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int X;
    double Y;
    cin >> X >> Y;
    double consumo = X / Y;
    cout << fixed << setprecision(3) << consumo << " km/l" << endl;
    return 0;
}
