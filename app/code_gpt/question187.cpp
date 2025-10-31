/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<std::string> alunos(N);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> alunos[i];
    }
    
    std::sort(alunos.begin(), alunos.end());
    
    std::cout << alunos[K - 1] << std::endl;
    
    return 0;
}
