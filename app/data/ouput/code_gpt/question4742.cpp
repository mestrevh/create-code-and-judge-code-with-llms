/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int peso1 = 6;
    const int peso2 = 4;
    double nota1, nota2;
    
    cin >> nota1 >> nota2;
    double media = (nota1 * peso1 + nota2 * peso2) / (peso1 + peso2);
    
    cout << fixed << setprecision(1) << "Média= " << media << endl;
    return 0;
}
