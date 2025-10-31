/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>
#include <utility>

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::unordered_map<int, int> count;
        bool possible = true;

        for (int i = 0; i < n; ++i) {
            int from, to;
            std::cin >> from >> to;
            count[std::make_pair(from, to)]++;
            count[std::make_pair(to, from)]--;
        }

        for (const auto& pair : count) {
            if (pair.second != 0) {
                possible = false;
                break;
            }
        }

        std::cout << (possible ? "YES" : "NO") << std::endl;
    }
    return 0;
}
