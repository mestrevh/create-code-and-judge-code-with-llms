/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        std::cin >> numbers[i];
    }

    std::map<int, int> frequency;
    for (int num : numbers) {
        frequency[num]++;
    }

    std::vector<int> keys;
    for (const auto& pair : frequency) {
        keys.push_back(pair.first);
    }
    
    std::sort(keys.begin(), keys.end());
    for (int key : keys) {
        std::cout << key << " " << frequency[key] << std::endl;
    }

    return 0;
}
