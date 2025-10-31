/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string str;
    char ch;
    std::getline(std::cin, str);
    std::cin >> ch;

    size_t index = str.find(ch);
    if (index != std::string::npos) {
        std::cout << index << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}
