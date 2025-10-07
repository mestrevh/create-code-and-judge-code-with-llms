/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m;
    std::cin >> m;

    std::vector<std::string> fragments(3);
    std::cin >> fragments[0] >> fragments[1] >> fragments[2];

    std::string best_name;
    int max_matches = -1;
    int max_sum_len = -1;
    int culprit_count = 0;

    for (int i = 0; i < m; ++i) {
        std::string name, dna;
        char hyphen;

        std::cin >> name >> hyphen >> dna;

        int current_matches = 0;
        int current_sum_len = 0;

        for (const std::string& frag : fragments) {
            if (dna.find(frag) != std::string::npos) {
                current_matches++;
                current_sum_len += frag.length();
            }
        }

        if (current_matches > max_matches) {
            max_matches = current_matches;
            max_sum_len = current_sum_len;
            best_name = name;
            culprit_count = 1;
        } else if (current_matches == max_matches) {
            if (current_sum_len > max_sum_len) {
                max_sum_len = current_sum_len;
                best_name = name;
                culprit_count = 1;
            } else if (current_sum_len == max_sum_len) {
                culprit_count++;
            }
        }
    }

    if (culprit_count == 1) {
        std::cout << "X reponsavel por essa atrocidade foi " << best_name << "!\n";
    } else {
        std::cout << "Nao pegamos x pilantra desse vez...\n";
    }

    return 0;
}
