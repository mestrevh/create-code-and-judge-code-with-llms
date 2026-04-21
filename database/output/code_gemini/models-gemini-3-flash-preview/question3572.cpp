/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long total_days;
    if (!(std::cin >> total_days)) return 0;

    long long years = total_days / 365;
    long long remaining_after_years = total_days % 365;
    long long weeks = remaining_after_years / 7;
    long long days = remaining_after_years % 7;

    std::cout << years << " ano(s), " << weeks << " semana(s) e " << days << " dia(s)" << std::endl;

    return 0;
}