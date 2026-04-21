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

    double discount = 0;

    if (salary <= 1751.81) {
        discount = salary * 0.08;
    } else if (salary <= 2919.72) {
        discount = salary * 0.09;
    } else if (salary <= 5839.45) {
        discount = salary * 0.11;
    } else {
        discount = 5839.45 * 0.11;
    }

    cout << "Desconto do INSS: R$ " << fixed << setprecision(2) << discount << endl;

    return 0;
}