/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

/**
 * Problema: Soma de custo mínimo.
 * Objetivo: Minimizar o custo total de somar N números, onde cada soma tem custo igual ao seu resultado.
 * Técnica: Algoritmo guloso utilizando uma Fila de Prioridade (Min-Heap), similar à Codificação de Huffman.
 * Complexidade de Tempo: O(N log N) por caso de teste.
 * Complexidade de Espaço: O(N) para armazenar os elementos na heap.
 */

int main() {
    // Otimização de I/O padrão do C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, seed, a, b, c;

    // Leitura dos casos de teste até o fim da entrada
    while (cin >> n >> seed >> a >> b >> c) {
        // Embora os limites indiquem N >= 1, uma verificação de segurança é boa prática
        if (n <= 0) continue;

        // Fila de prioridade mínima (Min-Heap) para extrair sempre os dois menores elementos
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        // Geração da sequência de acordo com a regra linear congruencial fornecida
        long long cur = seed;
        long long total_sum = cur;
        pq.push(cur);
        
        for (int i = 1; i < n; ++i) {
            // conjunto[i] = (conjunto[i-1] * a + b) % c
            // Usamos long long para evitar overflow no produto conjunto[i-1] * a
            cur = (cur * a + b) % c;
            total_sum += cur;
            pq.push(cur);
        }
        
        long long total_cost = 0;

        // Se N = 1, não há operações de soma, portanto o custo é 0.
        // O loop while (pq.size() > 1) lida corretamente com esse caso.
        while (pq.size() > 1) {
            // Retira os dois menores elementos atuais
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            
            // O custo desta operação é o valor da soma dos dois elementos
            long long combined = x + y;
            total_cost += combined;
            
            // Reinsere o resultado da soma na heap para ser processado em novas operações
            pq.push(combined);
        }
        
        // Saída do formato S C (Soma Total e Custo Mínimo Total)
        cout << total_sum << " " << total_cost << "\n";
    }
    
    return 0;
}