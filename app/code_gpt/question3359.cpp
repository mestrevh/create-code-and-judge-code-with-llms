/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

std::string invertMove(const std::string& move) {
    if (move.size() == 0) return "";
    if (move.back() == '\'') return move.substr(0, move.size() - 1);
    if (move == "U2" || move == "D2" || move == "L2" || move == "R2" || move == "F2" || move == "B2") return move;
    return move + "'";
}

int main() {
    std::string input, move;
    std::vector<std::string> moves;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    while (iss >> move) {
        moves.push_back(invertMove(move));
    }
    for (int i = moves.size() - 1; i >= 0; --i) {
        std::cout << moves[i] << (i > 0 ? " " : "");
    }
    std::cout << std::endl;
    return 0;
}
