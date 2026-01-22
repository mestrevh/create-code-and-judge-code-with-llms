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
    int word_count = 0;
    
    while (ss >> word) {
        word_count++;
    }
    
    if (word_count > 0 && word_count % 2 == 0) {
        std::cout << "SIM\n";
    } else {
        std::cout << "NÃO\n";
    }
    
    return 0;
}
