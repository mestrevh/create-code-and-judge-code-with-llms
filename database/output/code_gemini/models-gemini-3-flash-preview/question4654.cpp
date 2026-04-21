/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    while (std::getline(std::cin, line)) {
        for (char &c : line) {
            switch (c) {
                case '0':
                    c = 'o';
                    break;
                case '1':
                    c = 'i';
                    break;
                case '3':
                    c = 'e';
                    break;
                case '4':
                    c = 'a';
                    break;
                case '5':
                    c = 's';
                    break;
                default:
                    break;
            }
        }
        std::cout << line << "\n";
    }

    return 0;
}