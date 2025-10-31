/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int total_diapers_needed = 0;
    int age;
    std::string should_continue;

    while (std::cin >> age >> should_continue) {
        if (age <= 2) {
            total_diapers_needed += 9 * 30;
        } else {
            total_diapers_needed += 6 * 30;
        }

        if (std::tolower(static_cast<unsigned char>(should_continue[0])) == 'n') {
            break;
        }
    }

    int packs_to_buy = (total_diapers_needed + 99) / 100;
    int leftover_diapers = (packs_to_buy * 100) - total_diapers_needed;

    std::cout << packs_to_buy << std::endl;
    std::cout << leftover_diapers << std::endl;

    return 0;
}
