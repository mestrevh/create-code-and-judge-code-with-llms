/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int contarCaracteres(const std::string& s) {
    int count = 0;
    for (char c : s) {
        count++;
    }
    return count;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::cout << contarCaracteres(s) << std::endl;
    return 0;
}
