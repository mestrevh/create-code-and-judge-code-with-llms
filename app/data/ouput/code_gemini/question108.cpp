/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> freq(10, 0);

    for (int i = 0; i < n; ++i) {
        double v;
        std::cin >> v;

        int index;
        if (v <= 1.0) {
            index = 0;
        } else {
            index = static_cast<int>(ceil(v)) - 1;
        }
        
        freq[index]++;
    }

    std::cout << "^\n";

    for (int i = 9; i >= 0; --i) {
        std::cout << "|";
        for (int j = 0; j < freq[i]; ++j) {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    std::cout << "+------------>\n";

    return 0;
}
