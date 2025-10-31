/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

long long calculate_courage(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return calculate_courage(n - 1) + calculate_courage(n - 2);
}

void check_person(double shyness, int drinks, const std::string& name) {
    long long courage = calculate_courage(drinks);
    if (shyness > courage) {
        std::cout << "Nao foi dessa vez!! " << name << " nao teve coragem o suficiente.\n";
    } else {
        std::cout << "Esse pode ser o comeco de algo novo!! " << name << " vai cantar!!\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double troy_shyness, gabriella_shyness;
    int troy_drinks, gabriella_drinks;

    std::cin >> troy_shyness >> troy_drinks;
    std::cin >> gabriella_shyness >> gabriella_drinks;

    check_person(troy_shyness, troy_drinks, "Troy");
    check_person(gabriella_shyness, gabriella_drinks, "Gabriella");

    return 0;
}
