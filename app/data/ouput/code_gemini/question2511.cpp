/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::string> bag_items(5);
    for (int i = 0; i < 5; ++i) {
        std::getline(std::cin, bag_items[i]);
    }

    std::string blank_line;
    std::getline(std::cin, blank_line);

    std::set<std::string> guesses;
    for (int i = 0; i < 6; ++i) {
        std::string guess;
        std::getline(std::cin, guess);
        guesses.insert(guess);
    }

    int found_count = 0;
    for (const auto& item : bag_items) {
        if (guesses.count(item)) {
            found_count++;
        }
    }

    if (found_count == 5) {
        std::cout << "Could I be more happy?" << std::endl;
    } else {
        std::cout << "It is all just a moo point" << std::endl;
    }

    return 0;
}
