/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> numeros(10);
    double soma = 0.0;
    for (int i = 0; i < 10; ++i) {
        std::cin >> numeros[i];
        soma += numeros[i];
    }

    double media = soma / 10.0;

    int count_ultimo = 0;
    int count_pares = 0;
    int count_div3 = 0;
    std::vector<int> maiores_que_media;

    int ultimo_numero = numeros.back();

    for (int num : numeros) {
        if (num == ultimo_numero) {
            count_ultimo++;
        }
        if (num % 2 == 0) {
            count_pares++;
        }
        if (num % 3 == 0) {
            count_div3++;
        }
        if (static_cast<double>(num) > media) {
            maiores_que_media.push_back(num);
        }
    }

    std::cout << "Media: " << std::fixed << std::setprecision(1) << media << std::endl;
    std::cout << "Ultimo numero: " << count_ultimo << std::endl;
    std::cout << "Pares: " << count_pares << std::endl;
    std::cout << "Divisiveis por 3: " << count_div3 << std::endl;
    
    std::cout << "Lista maiores que a media: [";
    for (size_t i = 0; i < maiores_que_media.size(); ++i) {
        std::cout << maiores_que_media[i];
        if (i < maiores_que_media.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
