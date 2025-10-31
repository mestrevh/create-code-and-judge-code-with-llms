/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n && n != 0) {
        std::vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> p[i];
        }

        long long total_presses = 0;
        std::map<int, int> current_positions;

        for (int i = 0; i < n; ++i) {
            int target_cmd = p[i];
            int pos;

            auto it = current_positions.find(target_cmd);
            if (it == current_positions.end()) {
                pos = target_cmd + i;
            } else {
                pos = it->second;
            }

            total_presses += pos;

            for (auto& pair : current_positions) {
                pair.second++;
            }
            current_positions[target_cmd] = 1;
        }
        std::cout << total_presses << "\n";
    }

    return 0;
}
