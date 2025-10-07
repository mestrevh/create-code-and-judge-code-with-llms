/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string texto;
    std::getline(std::cin, texto);

    std::string palavraAntiga, palavraNova;
    std::getline(std::cin, palavraAntiga);
    std::getline(std::cin, palavraNova);

    size_t pos = 0;
    while ((pos = texto.find(palavraAntiga, pos)) != std::string::npos) {
        texto.replace(pos, palavraAntiga.length(), palavraNova);
        pos += palavraNova.length();
    }

    std::cout << texto << std::endl;

    return 0;
}
