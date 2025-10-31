/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <ios>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> matriculas;
    int matricula;

    while (std::cin >> matricula && matricula != -1) {
        matriculas.push_back(matricula);
    }

    int x;
    std::cin >> x;

    std::cout << matriculas[x - 1] << std::endl;

    return 0;
}
