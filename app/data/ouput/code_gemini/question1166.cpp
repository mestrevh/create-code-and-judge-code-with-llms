/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string line;
    std::getline(std::cin, line);
    for (char &c : line) {
        if (c >= 'a' && c <= 'z') {
            c = 'z' - (c - 'a');
        }
    }
    std::cout << line << std::endl;
    return 0;
}
