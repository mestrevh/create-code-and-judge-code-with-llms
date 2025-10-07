/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

void print_vector(const std::vector<int>& vec) {
    std::cout << "[ ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << "]\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0) {
        int pos;
        if(std::cin >> pos) {
            // consume the position input if n is not 0 but negative, though problem implies n>=0
        }
        std::cout << "[ ]\n";
        std::cout << "A lista estah vazia - nao eh possivel remover elementos\n";
        return 0;
    }

    std::vector<int> numbers;
    numbers.reserve(n);
    for (int i = 0; i < n; ++i) {
        int temp;
        std::cin >> temp;
        numbers.push_back(temp);
    }

    int pos;
    std::cin >> pos;

    print_vector(numbers);

    if (pos < 0 || pos >= n) {
        std::cout << "Nao eh possivel remover o elemento\n";
    } else {
        int removed_item = numbers[pos];
        std::cout << "O item " << removed_item << " serah removido da lista\n";

        std::vector<int> new_numbers;
        new_numbers.reserve(n - 1);
        for (int i = 0; i < n; ++i) {
            if (i != pos) {
                new_numbers.push_back(numbers[i]);
            }
        }
        print_vector(new_numbers);
    }

    return 0;
}
