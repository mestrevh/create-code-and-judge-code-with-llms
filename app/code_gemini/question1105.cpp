/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> values(10);
    for (int i = 0; i < 10; ++i) {
        std::cin >> values[i];
    }

    int max_value = values[0];
    for (int i = 1; i < 10; ++i) {
        if (values[i] > max_value) {
            max_value = values[i];
        }
    }

    int index_sum = 0;
    for (int i = 0; i < 10; ++i) {
        if (values[i] == max_value) {
            index_sum += i;
        }
    }

    std::cout << index_sum << std::endl;

    return 0;
}
