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

    int total_seconds = 0;
    bool found = false;
    int found_chest = 0;
    int found_pos = 0;

    for (int i = 0; i < n; ++i) {
        int chest_num;
        std::cin >> chest_num;
        
        for (int j = 1; j <= 4; ++j) {
            std::string item;
            std::cin >> item;
            total_seconds += 5;
            if (item == "lampada") {
                found = true;
                found_chest = chest_num;
                found_pos = j;
                goto end_search;
            }
        }
        total_seconds += 30;
    }

end_search:
    int minutes = total_seconds / 60;
    int seconds = total_seconds % 60;

    if (found) {
        std::cout << "Encontrei a lâmpada em " << minutes << "m" << seconds << "s! É o item " << found_pos << " do baú " << found_chest << "!\n";
    } else {
        std::cout << "Perdi " << minutes << "m" << seconds << "s da minha vida e não encontrei. Desisto!\n";
    }

    return 0;
}
