/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int C;
    int D;
    std::cin >> C >> D;

    std::string winner_name;
    int min_time = std::numeric_limits<int>::max();

    for (int i = 0; i < C; ++i) {
        std::string name;
        int TL, DO, TO;
        std::cin >> name >> TL >> DO >> TO;

        int base_time_seconds = TL * 60;
        int obstacle_count = 0;

        for (int dist = DO; dist <= D; dist += DO) {
            obstacle_count++;
        }
        
        int total_time = base_time_seconds + (obstacle_count * TO);

        if (total_time < min_time) {
            min_time = total_time;
            winner_name = name;
        }
    }

    std::cout << winner_name << " venceu a corrida em " << min_time << " segundos!\n";

    return 0;
}
