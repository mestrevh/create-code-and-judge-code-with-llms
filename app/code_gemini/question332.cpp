/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s;
    std::getline(std::cin, s);
    for (char &c : s) {
        c = toupper(c);
    }
    std::cout << s << std::endl;
    return 0;
}
