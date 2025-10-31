/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string texto;
    std::getline(std::cin, texto);
    
    int contagem = 0;
    for (char c : texto) {
        if (c == 'a' || c == 'A') {
            contagem++;
        }
    }
    
    std::cout << contagem << std::endl;
    return 0;
}
