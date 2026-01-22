/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float valor;
    const float taxa = 5.08;
    for (int i = 0; i < 3; i++) {
        cin >> valor;
        cout << fixed << setprecision(2) << valor * taxa << endl;
    }
    return 0;
}
