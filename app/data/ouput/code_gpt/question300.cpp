/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    int N;
    std::cin >> N;

    int altura = 0, distancia = 0;
    bool sentido = true; // true -> frente, false -> trás
    
    while (N--) {
        char comando;
        std::cin >> comando;

        if (comando == 'S') {
            if (altura < 200) altura += 10;
        } else if (comando == 'D') {
            if (altura > 0) altura -= 10;
        } else if (comando == 'F') {
            if (altura > 0 && distancia < 2000) {
                distancia += (sentido ? 10 : -10);
                if (distancia > 2000) distancia = 2000;
            }
        } else if (comando == 'V') {
            if (altura > 0 && distancia < 2000) {
                distancia += (sentido ? 10 : -10);
                if (distancia > 2000) distancia = 2000;
                sentido = !sentido;
            }
        }
    }
    
    std::cout << altura << " " << distancia << std::endl;
    return 0;
}
