/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);

    std::vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }

    if (arr.empty()) {
        return 0;
    }

    int max_val = 0;
    if (!arr.empty()) {
        max_val = *std::max_element(arr.begin(), arr.end());
    }

    std::vector<int> count(max_val + 1, 0);
    for (int x : arr) {
        count[x]++;
    }

    for (int i = 0; i <= max_val; ++i) {
        std::cout << count[i] << (i == max_val ? "" : " ");
    }
    std::cout << '\n';

    bool first = true;
    for (int i = 0; i <= max_val; ++i) {
        for (int j = 0; j < count[i]; ++j) {
            if (!first) {
                std::cout << " ";
            }
            std::cout << i;
            first = false;
        }
    }
    std::cout << '\n';

    return 0;
}
