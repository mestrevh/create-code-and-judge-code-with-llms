/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void print_vector(const std::vector<int>& arr) {
    if (arr.empty()) {
        return;
    }
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i == arr.size() - 1 ? "" : " ");
    }
    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        std::vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (!arr.empty()) {
            print_vector(arr);

            int n = arr.size();
            for (int i = 0; i < n - 1; ++i) {
                int min_idx = i;
                for (int j = i + 1; j < n; ++j) {
                    if (arr[j] < arr[min_idx]) {
                        min_idx = j;
                    }
                }
                
                if (min_idx != i) {
                    std::swap(arr[i], arr[min_idx]);
                    print_vector(arr);
                }
            }
        }
    }

    return 0;
}
