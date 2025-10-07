/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>

int findLargestEven(const std::vector<int>& numbers) {
    int max_even = INT_MIN;
    bool found_even = false;

    for (int num : numbers) {
        if (num % 2 == 0) {
            if (!found_even) {
                max_even = num;
                found_even = true;
            } else {
                if (num > max_even) {
                    max_even = num;
                }
            }
        }
    }
    return max_even;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::getline(std::cin, line);

    for (char& c : line) {
        if (c == '[' || c == ']' || c == ',') {
            c = ' ';
        }
    }

    std::stringstream ss(line);
    std::vector<int> numbers;
    int num;
    while (ss >> num) {
        numbers.push_back(num);
    }
    
    std::cout << findLargestEven(numbers) << std::endl;

    return 0;
}
