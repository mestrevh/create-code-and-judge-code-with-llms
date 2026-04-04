/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double salary;
    if (!(cin >> salary)) return 0;

    int percent;
    if (salary <= 280.00) {
        percent = 20;
    } else if (salary <= 700.00) {
        percent = 15;
    } else if (salary < 1500.00) {
        percent = 10;
    } else {
        percent = 5;
    }

    double increase = salary * (percent / 100.0);
    double newSalary = salary + increase;

    cout << "Informe o salario do colaborador:" << endl;
    cout << "Salario antes do reajuste: " << salary << endl;
    cout << "Percentual de aumento aplicado: " << percent << "%" << endl;
    cout << "Valor do aumento: " << increase << endl;
    cout << "Salario com reajuste: " << newSalary << endl;

    return 0;
}