/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);
    
    size_t pos = 0;
    while ((pos = input.find("vírgula", pos)) != std::string::npos) {
        input.replace(pos, 7, ",");
        pos++;
    }
    
    std::cout << input << std::endl;
    return 0;
}
