/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

void generate_fib_sequence(std::vector<long long>& fib_numbers, int n) {
    if (fib_numbers.size() >= n) {
        return;
    }

    if (fib_numbers.empty()) {
        fib_numbers.push_back(0);
    } else if (fib_numbers.size() == 1) {
        fib_numbers.push_back(1);
    } else {
        long long next_fib = fib_numbers.back() + fib_numbers[fib_numbers.size() - 2];
        fib_numbers.push_back(next_fib);
    }

    generate_fib_sequence(fib_numbers, n);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n > 0) {
        std::vector<long long> fib_seq;
        generate_fib_sequence(fib_seq, n);

        for (int i = n - 1; i >= 0; --i) {
            std::cout << fib_seq[i];
            if (i > 0) {
                std::cout << " ";
            }
        }
    }
    
    std::cout << std::endl;

    return 0;
}
