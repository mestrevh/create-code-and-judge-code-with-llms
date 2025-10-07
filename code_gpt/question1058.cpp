/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double temperatura, massaMolar;
    const double constante = 8.31;

    cin >> temperatura >> massaMolar;
    double velocidadeMedia = sqrt((3 * constante * temperatura) / massaMolar);
    
    cout << fixed << setprecision(2) << velocidadeMedia << endl;

    return 0;
}
