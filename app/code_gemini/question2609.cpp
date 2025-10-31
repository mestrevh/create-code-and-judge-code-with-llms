/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

void print_vector(const std::vector<int>& vec) {
    std::cout << "[";
    if (!vec.empty()) {
        std::cout << " ";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i];
            if (i < vec.size() - 1) {
                std::cout << " ";
            }
        }
        std::cout << " ";
    } else {
        std::cout << " ";
    }
    std::cout << "]\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> v;
    for (int i = 0; i < n; ++i) {
        int element;
        std::cin >> element;
        v.push_back(element);
    }

    int pos, val;
    std::cin >> pos >> val;

    print_vector(v);

    if (pos < 0 || pos > n) {
        std::cout << "A posicao " << pos << " estah fora do intervalo\n";
    } else {
        std::vector<int> new_v;
        new_v.reserve(n + 1);

        for (int i = 0; i < pos; ++i) {
            new_v.push_back(v[i]);
        }
        
        new_v.push_back(val);
        
        for (int i = pos; i < n; ++i) {
            new_v.push_back(v[i]);
        }
        
        print_vector(new_v);
    }

    return 0;
}
