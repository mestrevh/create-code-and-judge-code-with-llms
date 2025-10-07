/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line == "_") break;
        int count = 0;
        for (char& c : line) {
            if (c == '+') {
                count++;
                if (count % 2 == 1) c = '*';
                else c = '#';
            }
        }
        std::cout << line << std::endl;
    }
    return 0;
}
