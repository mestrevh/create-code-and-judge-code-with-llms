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

    double adjusted_salary;
    if (salary < 1000.0) {
        adjusted_salary = salary * 1.30;
    } else if (salary <= 2000.0) {
        adjusted_salary = salary * 1.10;
    } else {
        adjusted_salary = salary;
    }

    cout << fixed << setprecision(2) << adjusted_salary << "\n";

    return 0;
}