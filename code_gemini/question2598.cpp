/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

void print_vector(const std::vector<int>& v) {
    std::cout << "[";
    if (!v.empty()) {
        std::cout << " " << v[0];
        for (size_t i = 1; i < v.size(); ++i) {
            std::cout << " " << v[i];
        }
        std::cout << " ";
    }
    std::cout << "]\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int to_remove;
    std::cin >> to_remove;

    print_vector(arr);

    if (n == 0) {
        std::cout << "A lista estah vazia - nao eh possivel remover elemento\n";
    } else {
        int remove_idx = -1;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == to_remove) {
                remove_idx = i;
                break;
            }
        }

        if (remove_idx != -1) {
            std::vector<int> new_arr;
            for (int i = 0; i < n; ++i) {
                if (i != remove_idx) {
                    new_arr.push_back(arr[i]);
                }
            }
            print_vector(new_arr);
        } else {
            std::cout << "Nao eh possivel remover o elemento " << to_remove << "\n";
        }
    }

    return 0;
}
