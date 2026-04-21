/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double salary;
    if (!(cin >> salary)) return 0;

    if (salary <= 2000.00) {
        cout << "Isento" << endl;
    } else {
        double tax = 0.0;
        if (salary > 4500.00) {
            tax += (salary - 4500.00) * 0.28;
            salary = 4500.00;
        }
        if (salary > 3000.00) {
            tax += (salary - 3000.00) * 0.18;
            salary = 3000.00;
        }
        if (salary > 2000.00) {
            tax += (salary - 2000.00) * 0.08;
        }
        
        cout << "R$ " << fixed << setprecision(2) << tax << endl;
    }

    return 0;
}