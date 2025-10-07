/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

struct Club {
    std::string name;
    double score;
};

bool compareClubs(const Club& a, const Club& b) {
    return a.score > b.score;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Club> clubs(n);

    for (int i = 0; i < n; ++i) {
        std::string name_temp;
        double marketValue_temp;
        int greatPlayers_temp;
        int titles_temp;
        std::string hasNeymar_temp;
        std::string isFlamengo2019_temp;

        std::cin >> std::ws;
        std::getline(std::cin, name_temp);
        std::cin >> marketValue_temp >> greatPlayers_temp >> titles_temp;
        std::cin >> hasNeymar_temp >> isFlamengo2019_temp;

        double current_score = marketValue_temp;
        current_score += greatPlayers_temp * 100.0;
        current_score += titles_temp * 2000.0;

        if (hasNeymar_temp == "sim") {
            current_score += 10000.0;
        }
        if (isFlamengo2019_temp == "sim") {
            current_score += 20000.0;
        }
        
        clubs[i] = {name_temp, current_score};
    }

    std::sort(clubs.begin(), clubs.end(), compareClubs);

    std::cout << std::fixed << std::setprecision(2);

    for (const auto& club : clubs) {
        std::cout << club.name << " " << club.score << std::endl;
    }

    return 0;
}
