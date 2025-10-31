/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

void print_array(const std::vector<int>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i < arr.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

bool binary_search_recursive(const std::vector<int>& arr, int k, int left, int right) {
    if (left > right) {
        return false;
    }

    int mid = left + (right - left) / 2;

    print_array(arr);

    if (arr[mid] == k) {
        std::cout << "  ---->  " << mid << std::endl;
        return true;
    } else {
        std::cout << "  ---->  " << arr[mid] << std::endl;
        if (arr[mid] < k) {
            return binary_search_recursive(arr, k, mid + 1, right);
        } else {
            return binary_search_recursive(arr, k, left, mid - 1);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int k, n;
    std::cin >> k >> n;

    std::string line;
    std::getline(std::cin >> std::ws, line);

    std::vector<int> arr;
    std::stringstream ss(line);
    std::string segment;

    while (std::getline(ss, segment, ',')) {
        arr.push_back(std::stoi(segment));
    }

    bool found = binary_search_recursive(arr, k, 0, n - 1);

    if (!found) {
        print_array(arr);
        std::cout << "  ---->  -1" << std::endl;
    }

    return 0;
}
