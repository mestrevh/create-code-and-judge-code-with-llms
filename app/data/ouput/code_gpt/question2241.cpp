/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    int N;
    std::cin >> N;
    std::string resultado = "Essas malandra, assanhadinha, que so quer ";
    for (int i = 0; i < N; i++) {
        resultado += "vrau";
        if (i < N - 1) resultado += " ";
    }
    std::cout << resultado << std::endl;
    return 0;
}
