/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstdio>

int read_4_bits() {
    int b3, b2, b1, b0;
    std::cin >> b3 >> b2 >> b1 >> b0;
    return b3 * 8 + b2 * 4 + b1 * 2 + b0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int instruction = read_4_bits();
    int value = read_4_bits();

    while (instruction != 15) {
        switch (instruction) {
            case 0:
                value = read_4_bits();
                break;
            case 2:
                printf("O registrador tem os seguintes valores:\n");
                printf("High: %d\n", instruction);
                printf("Low: %d\n", value);
                break;
            case 5:
                printf("%d\n", value * value);
                break;
            case 8:
                printf("%X\n", value);
                break;
            case 12: {
                int multiplier;
                std::cin >> multiplier;
                printf("%d\n", value * multiplier);
                break;
            }
            default:
                printf("ERRO: A instrucao nao existe.\n");
                break;
        }
        
        instruction = read_4_bits();
    }

    return 0;
}
