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

    long long a, b;
    std::cin >> a >> b;

    std::string s;
    std::cin >> s;

    long long total_potions = 0;
    long long current_potions_count = a % b;

    for (char day : s) {
        if (day == '1') {
            total_potions = (total_potions + current_potions_count) % b;
        }
        current_potions_count = (current_potions_count * current_potions_count) % b;
    }

    std::cout << total_potions << std::endl;

    return 0;
}
