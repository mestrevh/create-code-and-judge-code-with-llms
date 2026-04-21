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
    if (std::getline(std::cin, line)) {
        for (char &c : line) {
            if (c == 'a' || c == 'A') {
                c = '4';
            } else if (c == 'e' || c == 'E') {
                c = '3';
            } else if (c == 'i' || c == 'I') {
                c = '1';
            } else if (c == 'o' || c == 'O') {
                c = '0';
            } else if (c == 's' || c == 'S') {
                c = '5';
            }
        }
        std::cout << line << std::endl;
    }

    return 0;
}