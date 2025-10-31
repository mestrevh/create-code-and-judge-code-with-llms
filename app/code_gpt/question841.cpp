/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    double media = (a + b + c) / 3;
    int contador = 0;
    
    if (a > media) contador++;
    if (b > media) contador++;
    if (c > media) contador++;

    cout << contador << endl;
    return 0;
}
