/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

void contar_vogais(const std::string& str) {
    int a = 0, e = 0, i = 0, o = 0, u = 0;
    
    for (char ch : str) {
        ch = tolower(ch);
        switch (ch) {
            case 'a': a++; break;
            case 'e': e++; break;
            case 'i': i++; break;
            case 'o': o++; break;
            case 'u': u++; break;
        }
    }
    
    std::cout << "A: " << a << std::endl;
    std::cout << "E: " << e << std::endl;
    std::cout << "I: " << i << std::endl;
    std::cout << "O: " << o << std::endl;
    std::cout << "U: " << u << std::endl;
}

int main() {
    std::string palavra;
    std::getline(std::cin, palavra);
    contar_vogais(palavra);
    return 0;
}
