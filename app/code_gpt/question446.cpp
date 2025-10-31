/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int alunos;
    std::cin >> alunos;
    int pacotes = alunos / 3;
    int restantes = alunos % 3;
    double total = pacotes * 2.20 * 2 + restantes * 2.20;
    std::cout << std::fixed << std::setprecision(2) << total << std::endl;
    return 0;
}
