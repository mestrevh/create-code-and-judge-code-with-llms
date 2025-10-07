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
    std::string to_find = "vírgula";
    std::string replacement = ",";
    size_t pos = line.find(to_find);
    while (pos != std::string::npos) {
        line.replace(pos, to_find.length(), replacement);
        pos = line.find(to_find, pos + replacement.length());
    }
    std::cout << line << std::endl;
    return 0;
}
