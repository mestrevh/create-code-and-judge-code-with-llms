/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string s;
    char char1, char2;

    std::getline(std::cin, s);
    std::cin >> char1 >> char2;

    for (char& c : s) {
        if (c == char1) {
            c = char2;
        }
    }

    std::cout << s << std::endl;
    return 0;
}
