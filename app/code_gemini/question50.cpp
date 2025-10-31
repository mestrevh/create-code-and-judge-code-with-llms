/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    std::vector<double> heights(4);
    for (int i = 0; i < 4; ++i) {
        std::cin >> heights[i];
    }

    std::sort(heights.begin(), heights.end());

    std::cout << std::fixed << std::setprecision(2);

    std::cout << heights[0] << std::endl;
    std::cout << heights[2] << std::endl;
    std::cout << heights[3] << std::endl;
    std::cout << heights[1] << std::endl;

    return 0;
}
