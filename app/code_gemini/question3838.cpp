/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long calculated_score = 0;
    std::set<int> ids;
    bool cheat_detected = false;

    for (int i = 0; i < 5; ++i) {
        int id, weight;
        std::cin >> id >> weight;

        if (ids.count(id)) {
            cheat_detected = true;
        }
        ids.insert(id);

        long long current_instruction_score;
        long long base_value = (long long)id * weight;

        if (id % 17 == 0 && id % 2 == 0) {
            current_instruction_score = 0;
        } else if (id % 2 == 0 && (id % 3 == 0 || id % 5 == 0 || id % 7 == 0)) {
            current_instruction_score = (long long)id * (weight * 2);
        } else if (base_value % 2 != 0 && (base_value % 11 == 0 || base_value % 13 == 0 || base_value % 17 == 0 || base_value % 19 == 0)) {
            current_instruction_score = base_value / 2;
        } else {
            current_instruction_score = base_value;
        }
        
        calculated_score += current_instruction_score;
    }

    long long player_score;
    std::cin >> player_score;

    if (player_score != calculated_score) {
        cheat_detected = true;
    }

    if (cheat_detected) {
        std::cout << "UEPAAA TEMOS UM RATINHO\n";
    } else {
        std::cout << "barra limpa, khan\n";
    }

    return 0;
}
