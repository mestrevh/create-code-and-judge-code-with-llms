/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int idade;
    std::cin >> idade;

    if (idade >= 18) {
        std::cout << "Voce ja pode tirar habilitacao!" << std::endl;
        std::cout << "Voce tem direito a habilitacao ha " << (idade - 18) << " ano(s)" << std::endl;
    } else {
        std::cout << "Voce precisa esperar mais " << (18 - idade) << " ano(s)!" << std::endl;
    }

    return 0;
}
