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
    std::vector<int> frequency(10, 0);
    double value;

    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        if (value == 10.0) {
            frequency[9]++;
        } else {
            frequency[(int)(value) + (value > (int)value)]++;
        }
    }

    std::cout << "^\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << "|";
        for (int j = 0; j < frequency[i]; ++j) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    std::cout << "+------------>\n";
    
    return 0;
}
