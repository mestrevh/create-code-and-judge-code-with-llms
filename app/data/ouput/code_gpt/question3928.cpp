/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> fib(N);
    fib[0] = 1; fib[1] = 1;
    
    for (int i = 2; i < N; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    std::vector<int> input(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        std::cin >> input[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        if (input[i] != fib[i]) {
            std::cout << "Sherliro achou o termo " << fib[i] << " que deveria estar na posicao " << (i + 1) << std::endl;
            break;
        }
    }
    
    return 0;
}
