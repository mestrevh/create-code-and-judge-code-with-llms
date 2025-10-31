/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<std::string, int> wins;
    std::vector<std::string> houses_order = {"Gryffindor", "Slytherin", "Hufflepuff", "Ravenclaw"};

    for (const auto& house : houses_order) {
        wins[house] = 0;
    }

    int n;
    std::cin >> n;

    std::vector<std::string> match_lines(n);
    std::vector<std::string> score_lines(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> match_lines[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> score_lines[i];
    }

    for (int i = 0; i < n; ++i) {
        size_t x_pos = match_lines[i].find('x');
        std::string c1 = match_lines[i].substr(0, x_pos);
        std::string c2 = match_lines[i].substr(x_pos + 1);

        size_t dash_pos = score_lines[i].find('-');
        int p1 = std::stoi(score_lines[i].substr(0, dash_pos));
        int p2 = std::stoi(score_lines[i].substr(dash_pos + 1));

        if (p1 > p2) {
            wins[c1]++;
        } else if (p2 > p1) {
            wins[c2]++;
        }
    }

    int max_wins = 0;
    for (const auto& pair : wins) {
        if (pair.second > max_wins) {
            max_wins = pair.second;
        }
    }

    if (max_wins == 0) {
        for (const auto& house : houses_order) {
            std::cout << house << '\n';
        }
    } else {
        for (const auto& house : houses_order) {
            if (wins[house] == max_wins) {
                std::cout << house << '\n';
            }
        }
    }

    return 0;
}
