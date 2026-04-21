/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<double> heights(4);
    for (int i = 0; i < 4; ++i) {
        if (!(std::cin >> heights[i])) break;
    }

    std::sort(heights.begin(), heights.end());

    std::cout << std::fixed << std::setprecision(2);
    std::cout << heights[0] << "\n";
    std::cout << heights[2] << "\n";
    std::cout << heights[3] << "\n";
    std::cout << heights[1] << "\n";

    return 0;
}