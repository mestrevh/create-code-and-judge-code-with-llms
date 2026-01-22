/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<int, int> frequency;
    int number;

    while (std::cin >> number) {
        frequency[number]++;
    }

    int mode = 0;
    int max_frequency = 0;

    if (!frequency.empty()) {
        for (const auto& pair : frequency) {
            if (pair.second > max_frequency) {
                max_frequency = pair.second;
                mode = pair.first;
            }
        }
    }

    std::cout << "Moda = " << mode << std::endl;

    return 0;
}
