/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string nome1, nome2;
    int e1, e2;
    std::string c1, c2;
    double p1, p2;

    std::getline(std::cin, nome1);
    std::getline(std::cin, nome2);
    std::cin >> e1 >> e2;
    std::cin >> c1 >> c2;
    std::cin >> p1 >> p2;

    if (e1 > e2) {
        std::cout << "O hotel " << nome1 << " e a melhor opcao de estadia!\n";
    } else if (e2 > e1) {
        std::cout << "O hotel " << nome2 << " e a melhor opcao de estadia!\n";
    } else {
        if (c1 == "Sim" && c2 == "Nao") {
            std::cout << "O hotel " << nome1 << " e a melhor opcao de estadia!\n";
        } else if (c2 == "Sim" && c1 == "Nao") {
            std::cout << "O hotel " << nome2 << " e a melhor opcao de estadia!\n";
        } else {
            if (p1 < p2) {
                std::cout << "O hotel " << nome1 << " e a melhor opcao de estadia!\n";
            } else if (p2 < p1) {
                std::cout << "O hotel " << nome2 << " e a melhor opcao de estadia!\n";
            } else {
                std::cout << "Ambos os hoteis sao boas opcoes de estadia!\n";
            }
        }
    }

    return 0;
}
