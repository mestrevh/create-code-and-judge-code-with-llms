/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int dias_meta = 0;
    int soma_total = 0;
    
    for (int i = 0; i < 7; ++i) {
        int entregas;
        std::cin >> entregas;
        if (entregas >= 100) {
            dias_meta++;
        }
        soma_total += entregas;
    }
    
    int media = soma_total / 7;
    
    std::cout << dias_meta << std::endl;
    std::cout << media << std::endl;
    
    return 0;
}
