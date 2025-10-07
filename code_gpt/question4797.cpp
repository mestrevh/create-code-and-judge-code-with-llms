/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char letra;
    int inteiro;
    float decimal1, decimal2;

    cin >> letra >> inteiro >> decimal1 >> decimal2;

    cout << fixed << setprecision(2)
         << decimal2 << " " << decimal1 << " " << inteiro << " " << letra << endl;

    return 0;
}
