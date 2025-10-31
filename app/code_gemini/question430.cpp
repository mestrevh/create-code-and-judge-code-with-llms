/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    while (getline(std::cin, line)) {
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        int n, num_tracks;
        ss >> n >> num_tracks;

        std::vector<int> tracks(num_tracks);
        for (int i = 0; i < num_tracks; ++i) {
            ss >> tracks[i];
        }

        long long best_sum = 0;
        int best_mask = 0;

        for (int mask = 0; mask < (1 << num_tracks); ++mask) {
            long long current_sum = 0;
            for (int i = 0; i < num_tracks; ++i) {
                if ((mask >> i) & 1) {
                    current_sum += tracks[i];
                }
            }

            if (current_sum <= n) {
                if (current_sum > best_sum) {
                    best_sum = current_sum;
                    best_mask = mask;
                } else if (current_sum == best_sum) {
                    if (__builtin_popcount(mask) > __builtin_popcount(best_mask)) {
                        best_mask = mask;
                    }
                }
            }
        }

        for (int i = 0; i < num_tracks; ++i) {
            if ((best_mask >> i) & 1) {
                std::cout << tracks[i] << " ";
            }
        }
        std::cout << "sum:" << best_sum << std::endl;
    }

    return 0;
}
