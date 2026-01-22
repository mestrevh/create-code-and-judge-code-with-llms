/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::map<unsigned long long, int> counts;
    for (int i = 0; i < n - 1; ++i) {
        unsigned long long val;
        std::cin >> val;
        counts[val]++;
    }

    std::vector<unsigned long long> fib(n + 1);

    if (n >= 1) {
        fib[1] = 1;
    }
    if (n >= 2) {
        fib[2] = 1;
    }

    for (int i = 3; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (int i = 1; i <= n; ++i) {
        if (counts.count(fib[i]) && counts[fib[i]] > 0) {
            counts[fib[i]]--;
        } else {
            std::cout << "Sherliro achou o termo " << fib[i] << " que deveria estar na posicao " << i << std::endl;
            break;
        }
    }

    return 0;
}
