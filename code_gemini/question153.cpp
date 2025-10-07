/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

float vantagem(const std::vector<float>& candidato, const std::vector<float>& concorrente, int n) {
    float max_vantagem = 0.0f;
    for (int i = 0; i < n; ++i) {
        float diferenca = candidato[i] - concorrente[i];
        if (diferenca > max_vantagem) {
            max_vantagem = diferenca;
        }
    }
    return max_vantagem;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<float> candidato(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> candidato[i];
    }

    std::vector<float> concorrente(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> concorrente[i];
    }

    float resultado = vantagem(candidato, concorrente, n);

    std::cout << std::fixed << std::setprecision(2) << resultado << std::endl;

    return 0;
}
