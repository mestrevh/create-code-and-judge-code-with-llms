/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <list>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);
    
    std::list<std::string> result;
    auto it = result.begin();
    
    for (char c : input) {
        if (c == '[') {
            it = result.begin();
        } else if (c == ']') {
            it = result.end();
        } else {
            it = result.insert(it, std::string(1, c));
            ++it;
        }
    }
    
    for (const auto& str : result) {
        std::cout << str;
    }
    std::cout << std::endl;

    return 0;
}
