/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int num;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;

    while (true) {
        std::cout << "Digite um numero inteiro:" << std::endl;
        std::cin >> num;

        if (num < 0) {
            break;
        }

        if (num >= 0 && num <= 25) {
            count1++;
        } else if (num >= 26 && num <= 50) {
            count2++;
        } else if (num >= 51 && num <= 75) {
            count3++;
        } else if (num >= 76 && num <= 100) {
            count4++;
        }
    }

    std::cout << "Quantidade de numeros no intervalo 1: " << count1 << std::endl;
    std::cout << "Quantidade de numeros no intervalo 2: " << count2 << std::endl;
    std::cout << "Quantidade de numeros no intervalo 3: " << count3 << std::endl;
    std::cout << "Quantidade de numeros no intervalo 4: " << count4 << std::endl;

    return 0;
}
