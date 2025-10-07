/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float a, b;
    cin >> a >> b;
    float produto = a * b;
    float razao = a / b;
    cout << fixed << setprecision(4);
    cout << "Produto: " << produto << endl;
    cout << "Razao: " << razao << endl;
    return 0;
}
