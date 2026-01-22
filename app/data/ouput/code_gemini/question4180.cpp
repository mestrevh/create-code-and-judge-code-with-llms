/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0) {
        return 0;
    }

    std::vector<float> u(n);
    std::vector<float> v(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> u[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    bool are_equal = true;
    for (int i = 0; i < n; ++i) {
        if (u[i] != v[i]) {
            are_equal = false;
            break;
        }
    }

    if (are_equal) {
        std::cout << "Os vetores sao iguais, logo, a projecao de v na direcao de u, eh o proprio u." << std::endl;
        return 0;
    }

    float dot_product_vu = 0.0f;
    float dot_product_uu = 0.0f;

    for (int i = 0; i < n; ++i) {
        dot_product_vu += v[i] * u[i];
        dot_product_uu += u[i] * u[i];
    }
    
    float scalar = 0.0f;
    if (dot_product_uu != 0.0f) {
        scalar = dot_product_vu / dot_product_uu;
    }

    std::cout << "A projecao ortogonal de v na direcao de u eh:" << std::endl;
    std::cout << std::fixed << std::setprecision(3);

    for (int i = 0; i < n; ++i) {
        float proj_component = scalar * u[i];
        std::cout << "| " << proj_component << " |" << std::endl;
    }

    return 0;
}
