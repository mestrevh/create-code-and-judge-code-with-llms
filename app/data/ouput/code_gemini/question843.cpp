/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    std::string word;
    int count = 0;
    while (ss >> word) {
        count++;
    }
    std::cout << count << std::endl;
    return 0;
}
