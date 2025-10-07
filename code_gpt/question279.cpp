/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int number, hours;
    double valuePerHour, salary;

    cin >> number >> hours >> valuePerHour;
    salary = hours * valuePerHour;

    cout << "NUMBER = " << number << endl;
    cout << "SALARY = R$ " << fixed << setprecision(2) << salary << endl;

    return 0;
}
