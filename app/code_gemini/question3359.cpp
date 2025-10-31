/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::getline(std::cin, line);

    std::stringstream ss(line);
    std::string move;
    std::vector<std::string> moves;

    while (ss >> move) {
        moves.push_back(move);
    }

    bool first = true;
    for (int i = moves.size() - 1; i >= 0; --i) {
        if (!first) {
            std::cout << " ";
        }

        const std::string& m = moves[i];

        if (m.length() == 2) {
            if (m[1] == '\'') {
                std::cout << m.substr(0, 1);
            } else { // m[1] == '2'
                std::cout << m;
            }
        } else { // m.length() == 1
            std::cout << m << "'";
        }

        first = false;
    }
    std::cout << std::endl;

    return 0;
}
