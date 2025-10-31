/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void print_vector(const std::vector<int>& vec, const std::string& prefix) {
    std::cout << prefix;
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << " | ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    
    std::vector<int> arr;
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }

    if (arr.empty()) {
        return 0;
    }

    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        std::cout << "Menor elemento neste passo: " << arr[min_idx] << std::endl;
        
        std::swap(arr[i], arr[min_idx]);

        print_vector(arr, "Estado Atual: ");

        if (i < n - 2) {
            std::cout << std::endl;
        }
    }

    print_vector(arr, "Resultado Final: ");

    return 0;
}
