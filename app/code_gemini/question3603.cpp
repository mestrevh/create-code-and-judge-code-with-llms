/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void read_vector_from_line(std::vector<int>& vec) {
    std::string line;
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        int num;
        while (ss >> num) {
            vec.push_back(num);
        }
    }
}

bool is_sorted_ascending(const std::vector<int>& vec) {
    if (vec.size() <= 1) {
        return true;
    }
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> x, y;
    read_vector_from_line(x);
    read_vector_from_line(y);

    if (!is_sorted_ascending(x) || !is_sorted_ascending(y)) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::vector<int> z;
    z.reserve(x.size() + y.size());
    
    size_t i = 0, j = 0;

    while (i < x.size() && j < y.size()) {
        if (x[i] < y[j]) {
            z.push_back(x[i]);
            i++;
        } else {
            z.push_back(y[j]);
            j++;
        }
    }

    while (i < x.size()) {
        z.push_back(x[i]);
        i++;
    }

    while (j < y.size()) {
        z.push_back(y[j]);
        j++;
    }

    if (!z.empty()) {
        std::cout << z[0];
        for (size_t k = 1; k < z.size(); ++k) {
            std::cout << " " << z[k];
        }
    }
    std::cout << std::endl;

    return 0;
}
