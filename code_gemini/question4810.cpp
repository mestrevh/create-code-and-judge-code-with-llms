/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int good_places_count = 0;
    double max_score = -1.0;
    std::string best_place_name = "";

    for (int i = 0; i < n; ++i) {
        std::string name;
        double p, g, t;
        std::cin >> name >> p >> g >> t;

        double score = (3.0 * p + g + 2.0 * t) / 6.0;

        if (score > max_score) {
            max_score = score;
            best_place_name = name;
        }

        if (score >= 3.5) {
            good_places_count++;
        }
    }

    std::cout << "Temos " << good_places_count << " lugares pra visitar!\n";

    if (good_places_count > 0) {
        std::cout << "Devo comecar por " << best_place_name << "\n";
    } else {
        std::cout << "Puts. Melhor ficar em casa mesmo\n";
    }

    return 0;
}
