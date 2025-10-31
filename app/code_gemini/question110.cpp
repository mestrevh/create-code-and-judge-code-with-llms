/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <algorithm>

void print_y_label(int label) {
    std::cout << std::setw(3) << label << " +";
}

void print_y_separator() {
    std::cout << "     |";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> freq(10, 0);
    int ignored_count = 0;
    for (int k = 0; k < n; ++k) {
        double value;
        std::cin >> value;
        if (value < 0.0 || value > 10.0) {
            ignored_count++;
            continue;
        }
        
        int index;
        if (value <= 1.0) {
            index = 0;
        } else {
            index = static_cast<int>(ceil(value)) - 1;
        }
        if (index >= 0 && index < 10) {
            freq[index]++;
        }
    }

    int max_freq = 0;
    if (n > ignored_count) {
        max_freq = *std::max_element(freq.begin(), freq.end());
    }

    std::vector<int> heights(10, 0);
    if (max_freq > 0) {
        for (int i = 0; i < 10; ++i) {
            heights[i] = (static_cast<long long>(freq[i]) * 20) / max_freq;
        }
    }

    std::cout << "     ^\n";

    for (int h = 20; h >= 1; --h) {
        if (h == 20) {
             if (max_freq >= 10) std::cout << "  " << max_freq << " +"; else std::cout << "   " << max_freq << " +";
        } else if (h == 15) {
            int val = (max_freq * 3) / 4;
            if (val >= 10) std::cout << "  " << val << " +"; else std::cout << "   " << val << " +";
        } else if (h == 10) {
            int val = max_freq / 2;
            if (val >= 10) std::cout << "  " << val << " +"; else std::cout << "   " << val << " +";
        } else if (h == 5) {
            int val = max_freq / 4;
            if (val >= 10) std::cout << "  " << val << " +"; else std::cout << "   " << val << " +";
        } else {
            std::cout << "     |";
        }

        for (int i = 0; i < 10; ++i) {
            std::cout << " ";
            if (h <= heights[i]) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    
    std::cout << "   0 +---------+---------+>\n";
    std::cout << "    0.0       5.0      10.0\n";
    std::cout << "Valores ignorados: " << ignored_count << "\n";

    return 0;
}
