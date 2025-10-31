/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int d, g, p;
    std::cin >> d >> g >> p;
    int distancia_percorrida = 0;
    int postos_abastecidos = 0;
    bool chegou = true;

    for (int i = 1; i <= p; ++i) {
        int pos_posto = i * 20;
        if (pos_posto >= d) {
            break;
        }
        int dist_trecho = pos_posto - distancia_percorrida;
        if (g < dist_trecho) {
            chegou = false;
            break;
        }
        g -= dist_trecho;
        distancia_percorrida = pos_posto;
        g += 15;
        postos_abastecidos++;
    }

    if (chegou) {
        int dist_final = d - distancia_percorrida;
        if (g < dist_final) {
            chegou = false;
        }
    }

    if (chegou) {
        std::cout << "Finalmente cheguei, tive que abastecer em " << postos_abastecidos << " postos\n";
    } else {
        std::cout << "Xii... Acho que nao vai dar pra te ver, Jasmine\n";
    }

    return 0;
}
