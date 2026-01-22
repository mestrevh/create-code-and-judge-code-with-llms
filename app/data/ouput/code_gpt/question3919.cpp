/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> X;
    int x;
    while (std::cin >> x && x != -1 && X.size() < 20) {
        X.push_back(x);
    }
    int count = 0;
    for (int num : X) {
        if (num == N) count++;
    }
    std::cout << N << " aparece " << count << " vezes" << std::endl;
    return 0;
}
