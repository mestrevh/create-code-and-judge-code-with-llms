/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int cavaleiro, arqueiro, prisioneiro, cachorro;
    std::cin >> cavaleiro >> arqueiro >> prisioneiro >> cachorro;
    bool ataque_rapido = (cavaleiro == 0);
    bool espionar = (cavaleiro == 1 || arqueiro == 1 || prisioneiro == 1);
    bool sinalizar = (prisioneiro == 1 && arqueiro == 0);
    bool resgatar = ((cachorro == 1 && arqueiro == 0) || (cachorro == 0 && prisioneiro == 1 && cavaleiro == 0 && arqueiro == 0));
    std::cout << ataque_rapido << " " << espionar << " " << sinalizar << " " << resgatar << std::endl;
    return 0;
}
