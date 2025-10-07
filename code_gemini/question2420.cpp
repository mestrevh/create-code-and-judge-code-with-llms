/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int fome;
    std::cin >> fome;

    std::string sushi;
    int quantidade;

    for (int i = 0; i < 3; ++i) {
        std::cin >> sushi >> quantidade;
        if (sushi == "Hossomaki") {
            fome -= quantidade * 3;
        } else if (sushi == "Futomaki") {
            fome -= quantidade * 5;
        } else if (sushi == "Nigirizushi") {
            fome -= quantidade * 7;
        } else if (sushi == "Temaki") {
            fome -= quantidade * 10;
        }
    }

    if (fome <= 0) {
        std::cout << "Nossa, o Japao e um otimo lugar para comer, vou dar conta do recado!\n";
    } else if (fome <= 10) {
        std::cout << "Estou satisfeito mas nao sei se darei conta do recado\n";
    } else {
        std::cout << "Uma feijoada seria bem melhor... Estou me sentindo fraco\n";
    }

    return 0;
}
