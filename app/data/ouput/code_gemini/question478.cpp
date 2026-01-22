/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x;
    std::cin >> x;

    std::map<int, int> damages_at_time;
    for (int i = 0; i < x; ++i) {
        int d, t;
        std::cin >> d >> t;
        damages_at_time[t] += d;
    }

    int y;
    std::cin >> y;

    long long hp = 100;
    int last_time = 0;

    for (const auto& pair : damages_at_time) {
        int current_time = pair.first;
        int total_damage = pair.second;

        int delta_time = current_time - last_time;
        
        if (hp > 0) {
            hp += static_cast<long long>(delta_time) * y;
            hp = std::min(100LL, hp);
        }

        hp -= total_damage;

        if (hp <= 0) {
            break;
        }

        last_time = current_time;
    }

    if (hp > 0) {
        std::cout << "Inimigo Vivo\n";
    } else {
        std::cout << "Inimigo Morto\n";
    }

    return 0;
}
