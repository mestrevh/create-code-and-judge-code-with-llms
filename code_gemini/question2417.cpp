/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s1, s2, s3, s4;
    std::cin >> s1 >> s2 >> s3 >> s4;

    if (s1 == "Carne" && s2 == "Bamboo" && s3 == "Sal" && s4 == "Ovo") {
        std::cout << "Naruto - ¥500\n";
    } else if (s1 == "Carne" && s2 == "Bamboo" && s3 == "Shoyu" && s4 == "Ovo") {
        std::cout << "Luffy - ¥475\n";
    } else if (s1 == "Carne" && s2 == "Bamboo" && s3 == "Nori" && s4 == "Ovo") {
        std::cout << "Kirito - ¥450\n";
    } else if (s1 == "Carne" && s2 == "Cebolinha" && s3 == "Kimushi" && s4 == "Nori") {
        std::cout << "Misty - ¥600\n";
    } else {
        std::cout << "Está tentando inventar um novo prato? O chef aqui sou eu!\n";
    }

    return 0;
}
