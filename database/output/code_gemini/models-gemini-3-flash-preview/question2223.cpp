/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    if (!(std::cin >> s)) return 0;

    static const std::unordered_map<std::string, int> dict = {
        {"Zero", 0},
        {"Um", 1},
        {"Dois", 2},
        {"Tres", 3},
        {"Três", 3},
        {"Quatro", 4},
        {"Cinco", 5},
        {"Seis", 6},
        {"Sete", 7},
        {"Oito", 8},
        {"Nove", 9}
    };

    auto it = dict.find(s);
    if (it != dict.end()) {
        std::cout << it->second << "\n";
    }

    return 0;
}