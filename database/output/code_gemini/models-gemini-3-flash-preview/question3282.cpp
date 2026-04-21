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

    double salary, percentage;
    if (!(cin >> salary >> percentage)) return 0;

    double increase = salary * (percentage / 100.0);
    double new_salary = salary + increase;

    cout << fixed << setprecision(2) << increase << " " << new_salary << endl;

    return 0;
}