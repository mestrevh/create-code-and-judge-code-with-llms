/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    double a, b, c;
    cout << "Digite um numero:\n";
    cin >> a;
    cout << "Digite outro numero:\n";
    cin >> b;
    cout << "Digite outro numero:\n";
    cin >> c;
    double maior = max({a, b, c});
    cout << "Maior numero: " << maior << endl;
    return 0;
}
