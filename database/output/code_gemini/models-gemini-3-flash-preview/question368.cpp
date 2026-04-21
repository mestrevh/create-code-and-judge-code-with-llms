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

    double new_salary;
    if (salary > 500.0) {
        new_salary = salary * 1.10;
    } else if (salary > 300.0) {
        new_salary = salary * 1.07;
    } else {
        new_salary = salary * 1.05;
    }

    cout << fixed << setprecision(2) << new_salary << "\n";

    return 0;
}