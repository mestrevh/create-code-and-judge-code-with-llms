/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m_score, l_score;
    std::cin >> m_score >> l_score;

    int n;
    std::cin >> n;

    std::map<int, int> points_map;
    points_map[1] = 25;
    points_map[2] = 18;
    points_map[3] = 15;
    points_map[4] = 12;
    points_map[5] = 10;
    points_map[6] = 8;
    points_map[7] = 6;
    points_map[8] = 4;
    points_map[9] = 2;
    points_map[10] = 1;

    std::vector<std::string> m_ahead_races;
    std::vector<std::string> l_ahead_races;
    int m_ahead_count = 0;
    int l_ahead_count = 0;

    for (int i = 0; i < n; ++i) {
        std::string race_name;
        int m_pos, l_pos;
        std::cin >> race_name >> m_pos >> l_pos;

        if (points_map.count(m_pos)) {
            m_score += points_map[m_pos];
        }
        if (points_map.count(l_pos)) {
            l_score += points_map[l_pos];
        }

        if (m_pos < l_pos) {
            m_ahead_count++;
            m_ahead_races.push_back(race_name);
        } else {
            l_ahead_count++;
            l_ahead_races.push_back(race_name);
        }
    }

    if (m_score > l_score) {
        std::cout << "O vencedor e Marquinhos com " << m_score - l_score << " pontos a mais, ficando a frente em ";
        for (const auto& race : m_ahead_races) {
            std::cout << race << "/";
        }
        std::cout << "\n";
    } else if (l_score > m_score) {
        std::cout << "O vencedor e Luis com " << l_score - m_score << " pontos a mais, ficando a frente em ";
        for (const auto& race : l_ahead_races) {
            std::cout << race << "/";
        }
        std::cout << "\n";
    } else {
        if (m_ahead_count > l_ahead_count) {
            std::cout << "O vencedor e Marquinhos com 0 pontos a mais, ficando a frente em ";
            for (const auto& race : m_ahead_races) {
                std::cout << race << "/";
            }
            std::cout << "\n";
        } else {
            std::cout << "O vencedor e Luis com 0 pontos a mais, ficando a frente em ";
            for (const auto& race : l_ahead_races) {
                std::cout << race << "/";
            }
            std::cout << "\n";
        }
    }

    return 0;
}
