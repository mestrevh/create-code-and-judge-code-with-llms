/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int number;
    int hours;
    double valuePerHour;

    if (!(cin >> number >> hours >> valuePerHour)) return 0;

    double salary = hours * valuePerHour;

    cout << "NUMBER = " << number << "\n";
    cout << "SALARY = R$ " << fixed << setprecision(2) << salary << "\n";
    return 0;
}