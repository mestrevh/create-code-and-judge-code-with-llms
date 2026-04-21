/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Função recursiva para encontrar a posição da chave (-1) na sequência de túneis.
 * @param n O número total de túneis.
 * @param current A posição atual na sequência (1-indexed).
 * @return A posição onde a chave foi encontrada.
 */
int find_key_position(int n, int current) {
    if (current > n) {
        return 0;
    }
    
    int tunnel_id;
    if (!(cin >> tunnel_id)) {
        return 0;
    }
    
    if (tunnel_id == -1) {
        return current;
    }
    
    // Chamada recursiva com acumulador 'current' para manter o controle da posição.
    return find_key_position(n, current + 1);
}

int main() {
    // Otimização de I/O padrão para programação competitiva.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Leitura da quantidade de túneis.
    if (cin >> n) {
        // Encontra a posição do marcador de chave (-1) na sequência fornecida.
        // A lógica do problema indica que o tempo total é o dobro da posição da chave
        // na sequência de busca, considerando o percurso de ida e volta (2 minutos por túnel percorrido).
        int position = find_key_position(n, 1);
        
        // Saída do tempo estimado total (posição * 2).
        cout << position * 2 << endl;
    }

    return 0;
}