/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

std::string removeABC(std::string s) {
    std::string result;
    for (char c : s) {
        result += c;
        if (result.size() >= 3 && result.substr(result.size() - 3) == "abc") {
            result.erase(result.end() - 3, result.end());
        }
    }
    return result.empty() ? "string vazia" : result;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << removeABC(s) << std::endl;
    return 0;
}
