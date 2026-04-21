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
    int extra_hours;

    if (cin >> salary >> extra_hours) {
        double total_payment = salary + (salary * 0.05 * extra_hours);
        cout << fixed << setprecision(2) << total_payment << endl;
    }

    return 0;
}