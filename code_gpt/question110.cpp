/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    std::vector<double> values(n);
    std::vector<int> histogram(10, 0);
    int ignored = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
        if (values[i] < 0 || values[i] > 10) {
            ++ignored;
        } else if (values[i] == 10) {
            ++histogram[9];
        } else {
            histogram[(int)(values[i] * 10) / 10]++;
        }
    }

    int max_freq = *std::max_element(histogram.begin(), histogram.end());
    int scale = (max_freq > 0) ? (20.0 / max_freq) : 0;

    std::cout << std::string(5, ' ') << "^\n";
    for (int i = 20; i > 0; --i) {
        std::cout << std::string(5, ' ') << std::setw(2) << (i * max_freq / 20) << " +";
        for (int j = 0; j < 10; ++j) {
            if (histogram[j] * scale >= i) std::cout << " *";
            else std::cout << "  ";
        }
        std::cout << "\n";
    }
    std::cout << std::string(5, ' ') << "0 +---------+---------+>\n";
    std::cout << std::string(5, ' ') << "   0.0       5.0      10.0\n";
    std::cout << "Valores ignorados: " << ignored << std::endl;

    return 0;
}
