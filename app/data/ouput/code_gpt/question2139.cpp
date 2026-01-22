/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string palavra;
    std::getline(std::cin, palavra);
    
    if (palavra.substr(0, 3) == "des") {
        palavra.erase(0, 3);
    }
    
    std::cout << palavra << std::endl;
    return 0;
}
