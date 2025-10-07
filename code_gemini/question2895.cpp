/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double x_novo, y_novo;
    std::cin >> x_novo >> y_novo;

    double x_aluno, y_aluno;
    std::string nome_aluno;

    double min_dist = std::numeric_limits<double>::max();
    std::string nome_mais_proximo = "";

    while (std::cin >> x_aluno >> y_aluno >> nome_aluno) {
        double dx = x_novo - x_aluno;
        double dy = y_novo - y_aluno;
        double dist_atual = std::sqrt(dx * dx + dy * dy);

        if (dist_atual < min_dist) {
            min_dist = dist_atual;
            nome_mais_proximo = nome_aluno;
        }
    }

    if (min_dist < 10.0) {
        std::cout << "O aluno novo é mais parecido com " << nome_mais_proximo << std::endl;
    } else {
        std::cout << "Aparentemente ele não é tão chato assim" << std::endl;
    }

    return 0;
}
