/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>
#include <algorithm>
#include <functional>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss1(line);
    std::vector<int> first_array;
    int num;
    while (ss1 >> num) {
        first_array.push_back(num);
    }

    std::getline(std::cin, line);
    std::stringstream ss2(line);
    std::unordered_set<int> second_set;
    while (ss2 >> num) {
        second_set.insert(num);
    }

    std::vector<int> result;
    for (int val : first_array) {
        if (second_set.find(val) == second_set.end()) {
            result.push_back(val);
        }
    }

    std::sort(result.begin(), result.end(), std::greater<int>());

    if (!result.empty()) {
        std::cout << result[0];
        for (size_t i = 1; i < result.size(); ++i) {
            std::cout << " " << result[i];
        }
    }
    std::cout << std::endl;

    return 0;
}
