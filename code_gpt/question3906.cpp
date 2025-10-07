/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::vector<int> resultados;
    for (int i = 1500; i <= 2700; ++i) {
        if (i % 7 == 0 && i % 5 == 0) {
            resultados.push_back(i);
        }
    }
    std::ostringstream oss;
    for (size_t i = 0; i < resultados.size(); ++i) {
        oss << resultados[i];
        if (i < resultados.size() - 1) {
            oss << " ";
        }
    }
    std::cout << oss.str() << std::endl;
    return 0;
}
