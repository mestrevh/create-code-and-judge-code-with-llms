/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double salary;
    if (!(std::cin >> salary)) return 0;

    double new_salary = salary * 1.25;

    std::cout << std::fixed << std::setprecision(2) << new_salary << "\n";

    return 0;
}