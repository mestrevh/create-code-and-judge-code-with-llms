/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Optimization for fast I/O in C++
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // According to constraints, N <= 500,000
    std::vector<int> numbers;
    numbers.reserve(500000);

    int val;
    // Read all integers from the input until end of file
    while (std::cin >> val) {
        numbers.push_back(val);
    }

    // Sort the numbers. std::sort uses introsort, ensuring O(N log N) worst-case.
    // Given the 10-second time limit, this is extremely efficient.
    if (!numbers.empty()) {
        std::sort(numbers.begin(), numbers.end());

        // Output each element on a new line as specified
        for (size_t i = 0; i < numbers.size(); ++i) {
            std::cout << numbers[i] << "\n";
        }
    }

    return 0;
}