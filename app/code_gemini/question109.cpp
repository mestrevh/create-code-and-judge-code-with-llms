/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <algorithm>

int get_index(double value) {
    if (value <= 1.0) {
        return 0;
    }
    return static_cast<int>(std::ceil(value)) - 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> counts(10, 0);
    for (int i = 0; i < n; ++i) {
        double value;
        std::cin >> value;
        if (value >= 0.0 && value <= 10.0) {
            counts[get_index(value)]++;
        }
    }

    int max_freq = 0;
    if (n > 0) {
        max_freq = *std::max_element(counts.begin(), counts.end());
    }

    std::vector<int> bar_lengths(10);
    for (int i = 0; i < 10; ++i) {
        if (max_freq == 0) {
            bar_lengths[i] = 0;
        } else {
            bar_lengths[i] = static_cast<int>((static_cast<double>(counts[i]) * 20.0) / max_freq);
        }
    }

    std::cout << "     ^" << std::endl;

    for (int i = 9; i >= 0; --i) {
        if (i + 1 == 10) {
            std::cout << std::setw(4) << std::right << 10 << " |";
        } else if (i + 1 == 5) {
            std::cout << std::setw(4) << std::right << 5 << " |";
        } else {
            std::cout << "     |";
        }
        std::cout << std::string(bar_lengths[i], '*') << std::endl;
    }

    std::cout << std::setw(4) << std::right << 0 << " +----+----+----+----+>" << std::endl;

    std::vector<int> labels;
    labels.push_back(0);
    labels.push_back(max_freq / 4);
    labels.push_back(max_freq / 2);
    labels.push_back((max_freq * 3) / 4);
    labels.push_back(max_freq);

    std::vector<int> positions = {5, 10, 15, 20, 25};
    int current_pos = 0;

    for (size_t i = 0; i < labels.size(); ++i) {
        int target_pos = positions[i];
        std::string label_str = std::to_string(labels[i]);

        if (target_pos > current_pos) {
            std::cout << std::string(target_pos - current_pos, ' ');
        }
        
        std::cout << label_str;
        current_pos = target_pos + label_str.length();
    }
    std::cout << std::endl;

    return 0;
}
