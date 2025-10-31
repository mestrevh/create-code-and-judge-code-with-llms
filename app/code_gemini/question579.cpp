/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void print_array(const std::vector<int>& arr, const std::string& prefix) {
    std::cout << prefix;
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i < arr.size() - 1) {
            std::cout << " | ";
        }
    }
    std::cout << std::endl;
}

void quicksort(std::vector<int>& A, int p, int r);

int partition(std::vector<int>& A, int p, int r) {
    int pivot = A[r];
    std::cout << "Pivot: " << pivot << std::endl;

    std::cout << "Partition(A," << p + 1 << "," << r + 1 << "): ";
    std::vector<int> less_equal;
    std::vector<int> greater;
    for (int k = p; k < r; ++k) {
        if (A[k] <= pivot) {
            less_equal.push_back(A[k]);
        } else {
            greater.push_back(A[k]);
        }
    }

    for (size_t i = 0; i < less_equal.size(); ++i) {
        std::cout << less_equal[i] << (i < less_equal.size() - 1 ? " " : "");
    }

    std::cout << (less_equal.empty() ? "" : " ") << "<= " << pivot << " <" << (greater.empty() ? "" : " ");

    for (size_t i = 0; i < greater.size(); ++i) {
        std::cout << greater[i] << (i < greater.size() - 1 ? " " : "");
    }
    std::cout << std::endl;

    int i = p - 1;
    for (int j = p; j < r; ++j) {
        if (A[j] <= pivot) {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i + 1], A[r]);

    print_array(A, "Estado atual de A: ");
    std::cout << std::endl;

    return i + 1;
}

void quicksort(std::vector<int>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> numbers;
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    int num;
    while (ss >> num) {
        numbers.push_back(num);
    }

    if (numbers.empty()) {
        std::cout << "Estado inicial: " << std::endl;
        std::cout << std::endl;
        std::cout << "Resultado Final: " << std::endl;
        return 0;
    }

    print_array(numbers, "Estado inicial: ");
    std::cout << std::endl;

    quicksort(numbers, 0, static_cast<int>(numbers.size()) - 1);

    print_array(numbers, "Resultado Final: ");

    return 0;
}
