/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double salary;
    cin >> salary;

    double tax = 0.0;
    
    if (salary <= 2000.00) {
        cout << "Isento" << endl;
    } else if (salary <= 3000.00) {
        tax += (salary - 2000.00) * 0.08;
        cout << "R$ " << fixed << setprecision(2) << tax << endl;
    } else if (salary <= 4500.00) {
        tax += 1000.00 * 0.08; // 8% sobre os R$ 1000,00
        tax += (salary - 3000.00) * 0.18; // 18% sobre o que exceder R$ 3000,00
        cout << "R$ " << fixed << setprecision(2) << tax << endl;
    } else {
        tax += 1000.00 * 0.08; // 8% sobre os R$ 1000,00
        tax += 1500.00 * 0.18; // 18% sobre os R$ 1500,00
        tax += (salary - 4500.00) * 0.28; // 28% sobre o que exceder R$ 4500,00
        cout << "R$ " << fixed << setprecision(2) << tax << endl;
    }

    return 0;
}
