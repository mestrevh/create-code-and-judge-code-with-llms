/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    int raiz = 0;
    int impar = 1;
    while (n >= impar) {
        n -= impar;
        raiz++;
        impar += 2;
    }
    std::cout << raiz << std::endl;
    return 0;
}
