/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> freq(10, 0);
    for (int i = 0; i < n; ++i) {
        double value;
        std::cin >> value;
        if (value >= 0.0 && value < 10.0) {
            int index = (value == 10.0) ? 9 : static_cast<int>(value) + (value - static_cast<int>(value) > 0 ? 1 : 0);
            freq[index]++;
        }
    }

    int max_freq = *std::max_element(freq.begin(), freq.end());
    std::vector<int> histogram(10);
    for (int i = 0; i < 10; i++) {
        histogram[i] = (max_freq > 0) ? (freq[i] * 20) / max_freq : 0;
    }

    std::cout << std::setw(6) << "^\n";
    for (int y = 10; y >= 0; y -= 5) {
        std::cout << std::setw(3) << y << " |";
        for (int i = 0; i < 10; ++i) {
            if (y <= histogram[i]) std::cout << "*";
            else std::cout << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "   0 +";
    for (int i = 0; i < 4; ++i) std::cout << "----+";
    std::cout << ">\n";
    
    std::cout << "     0  ";
    for (int i = 0; i < 10; ++i) {
        std::cout << std::setw(3) << (i * 1 + (i < 9 ? 1 : 0));
    }
    std::cout << std::endl;

    return 0;
}
