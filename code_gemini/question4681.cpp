/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> hand;
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        int d1 = val / 10;
        int d2 = val % 10;
        if (d1 > d2) std::swap(d1, d2);
        hand.push_back({d1, d2});
    }

    int ponta1, ponta2;
    std::cin >> ponta1 >> ponta2;

    std::string action_str;
    std::cin >> action_str;

    bool possible = false;
    
    std::string code;
    size_t num_pos = 0;

    if (action_str.rfind("manbr", 0) == 0) {
        code = "manbr";
        num_pos = 5;
    } else if (action_str.rfind("rpf", 0) == 0) {
        code = "rpf";
        num_pos = 3;
    } else if (action_str.rfind("rrs", 0) == 0) {
        code = "rrs";
        num_pos = 3;
    } else if (action_str.rfind("dsfs", 0) == 0) {
        code = "dsfs";
    }
    
    if (code == "dsfs") {
        bool can_play = false;
        for (const auto& piece : hand) {
            if (piece.first == ponta1 || piece.second == ponta1 || 
                piece.first == ponta2 || piece.second == ponta2) {
                can_play = true;
                break;
            }
        }
        possible = !can_play;
    } else {
        std::string num_part = action_str.substr(num_pos);
        int num1 = std::stoi(num_part.substr(0, 3));
        int num2 = std::stoi(num_part.substr(3, 3));
        int x = num1 / num2;

        auto has_piece = [&](int p1, int p2) {
            if (p1 > p2) std::swap(p1, p2);
            std::pair<int, int> target = {p1, p2};
            for (const auto& piece : hand) {
                if (piece == target) return true;
            }
            return false;
        };

        if (code == "manbr") {
            if ((ponta1 == x && has_piece(ponta2, x)) || 
                (ponta2 == x && has_piece(ponta1, x))) {
                possible = true;
            }
        } else if (code == "rpf") {
            if (has_piece(ponta1, x) || has_piece(ponta2, x)) {
                possible = true;
            }
        } else if (code == "rrs") {
            if (ponta1 == x || ponta2 == x) {
                bool has_any_with_x = false;
                for (const auto& piece : hand) {
                    if (piece.first == x || piece.second == x) {
                        has_any_with_x = true;
                        break;
                    }
                }
                if (has_any_with_x) {
                    possible = true;
                }
            }
        }
    }

    if (possible) {
        std::cout << "ai maezinha\n";
    } else {
        std::cout << "cade o douze\n";
    }

    return 0;
}
