/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <vector>

int countSwaps(std::vector<int> arr, std::vector<int> sorted) {
    int swaps = 0;
    for (int i = 0; i < arr.size(); ++i) {
        while (arr[i] != sorted[i]) {
            std::swap(arr[i], arr[std::find(arr.begin(), arr.end(), sorted[i]) - arr.begin()]);
            swaps++;
        }
    }
    return swaps;
}

int main() {
    std::vector<int> numbers(4);
    for (int i = 0; i < 4; ++i) {
        std::cin >> numbers[i];
    }
    
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    
    std::cout << sorted[0] << " " << sorted[1] << " " << sorted[2] << " " << sorted[3] << std::endl;
    std::cout << countSwaps(numbers, sorted) << std::endl;

    return 0;
}
