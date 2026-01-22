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
    std::string line;
    std::getline(std::cin, line);
    for (char &c : line) {
        switch (tolower(c)) {
            case 'a':
                c = '4';
                break;
            case 'e':
                c = '3';
                break;
            case 'i':
                c = '1';
                break;
            case 'o':
                c = '0';
                break;
            case 's':
                c = '5';
                break;
        }
    }
    std::cout << line << std::endl;
    return 0;
}
