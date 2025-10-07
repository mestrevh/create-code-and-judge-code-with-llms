/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    
    std::vector<int> v;
    int num;
    while (ss >> num) {
        v.push_back(num);
    }

    if (v.empty()) {
        return 0;
    }

    int left = 0;
    int right = v.size() - 1;
    int mid = left + (right - left) / 2;

    int val_left = v[left];
    int val_mid = v[mid];
    int val_right = v[right];

    int pivot_value;
    int pivot_original_index;

    if ((val_left <= val_mid && val_mid <= val_right) || (val_right <= val_mid && val_mid <= val_left)) {
        pivot_value = val_mid;
        pivot_original_index = mid;
    } else if ((val_mid <= val_left && val_left <= val_right) || (val_right <= val_left && val_left <= val_mid)) {
        pivot_value = val_left;
        pivot_original_index = left;
    } else {
        pivot_value = val_right;
        pivot_original_index = right;
    }

    std::cout << pivot_value << std::endl;

    std::swap(v[pivot_original_index], v[right]);

    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (v[j] <= pivot_value) {
            i++;
            std::swap(v[i], v[j]);
        }
    }
    
    std::swap(v[i + 1], v[right]);

    for (size_t k = 0; k < v.size(); ++k) {
        std::cout << v[k] << (k == v.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}
