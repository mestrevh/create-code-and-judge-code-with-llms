/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * Problema: Macarronada
 * Objetivo: Determinar se três segmentos de reta, dados por suas coordenadas,
 * podem formar um triângulo. A condição fundamental para que três comprimentos
 * a, b e c formem um triângulo é a desigualdade triangular: a + b > c, 
 * a + c > b e b + c > a.
 * 
 * Estratégia: 
 * 1. Calcular o comprimento de cada segmento usando a fórmula da distância euclidiana.
 * 2. Ordenar os comprimentos.
 * 3. Verificar se a soma dos dois menores comprimentos é estritamente maior que o maior.
 * 4. Usar precisão de ponto flutuante (long double) para evitar erros de arredondamento.
 */

int main() {
    // Otimização de I/O padrão do C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Leitura do número de casos de teste
    if (!(cin >> n)) return 0;

    while (n--) {
        long double sides[3];
        for (int i = 0; i < 3; ++i) {
            long double x1, y1, x2, y2;
            if (!(cin >> x1 >> y1 >> x2 >> y2)) break;
            
            // Cálculo do comprimento do segmento: sqrt((x2-x1)^2 + (y2-y1)^2)
            // hypot é mais preciso e lida melhor com grandes valores
            sides[i] = hypot(x1 - x2, y1 - y2);
        }

        // Ordenar os lados para facilitar a verificação da desigualdade triangular
        sort(sides, sides + 3);

        // A condição a + b > c é suficiente se c for o maior lado.
        // Usamos uma pequena margem (epsilon) para lidar com imprecisão de ponto flutuante.
        // No entanto, para triângulos estritos, a + b deve ser maior que c.
        if (sides[0] + sides[1] > sides[2] + 1e-10) {
            cout << "SIM" << "\n";
        } else {
            cout << "NAO" << "\n";
        }
    }

    return 0;
}