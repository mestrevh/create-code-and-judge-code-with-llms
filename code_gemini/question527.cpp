/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void print_vector(const std::vector<int>& v) {
    if (v.empty()) {
        return;
    }
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << (i == v.size() - 1 ? "" : " | ");
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
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }

    if (arr.size() <= 1) {
        std::cout << "Resultado Final: ";
        print_vector(arr);
        return 0;
    }

    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        
        std::cout << "Chave: " << key << std::endl;
        std::cout << "Estado Atual: ";
        print_vector(arr);

        size_t j = i;
        bool swapped = false;
        while (j > 0 && arr[j] < arr[j - 1]) {
            std::swap(arr[j], arr[j - 1]);
            print_vector(arr);
            swapped = true;
            j--;
        }
        
        if (i < arr.size() - 1) {
            std::cout << std::endl;
        }
    }

    std::cout << "Resultado Final: ";
    print_vector(arr);

    return 0;
}
