/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char dir;
    int dist;
    int pos = 20;

    while (std::cin >> dir && dir != 'x') {
        std::cin >> dist;

        if (dir == 'd') {
            std::cout << ".";
            std::cout << std::string(pos, ' ');
            for (int i = 0; i < dist; ++i) {
                std::cout << "->";
            }
            std::cout << '\n';
            pos += dist * 2;
        } else if (dir == 'e') {
            pos -= dist * 2;
            std::cout << ".";
            std::cout << std::string(pos, ' ');
            for (int i = 0; i < dist; ++i) {
                std::cout << "<-";
            }
            std::cout << '\n';
        } else if (dir == 'f') {
            for (int i = 0; i < dist; ++i) {
                std::cout << ".";
                std::cout << std::string(pos, ' ');
                std::cout << "|\n";
            }
        }
    }

    std::cout << ".";
    std::cout << std::string(pos, ' ');
    std::cout << "x\n";

    return 0;
}
