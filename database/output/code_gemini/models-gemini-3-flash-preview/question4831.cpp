/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problema: Pilhados
 * Especialista: Grande Mestre em Programação Competitiva
 * Estratégia: Simulação de pilha em O(N) por caso de teste.
 * Regras:
 * - Se a nova caixa 'n' tem mesma paridade que o topo, n = |n - topo|, remove topo.
 * - Repete sucessivamente até paridades diferentes ou pilha vazia.
 * - Se o resultado final n != 0, empilha n.
 * - Se a pilha estiver vazia no final, topo = -1.
 */

int main() {
    // Otimização de I/O para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Lê o número de rodadas (casos de teste)
    if (!(cin >> t)) return 0;

    for (int i = 1; i <= t; ++i) {
        // Vetor utilizado como pilha para acesso dinâmico eficiente
        vector<long long> stack;
        long long n;

        // Lê cada número n até encontrar 0 (marcador de fim de partida)
        while (cin >> n && n != 0) {
            // Enquanto a paridade de n for igual à paridade do topo da pilha
            while (!stack.empty() && (n % 2 == stack.back() % 2)) {
                long long top_val = stack.back();
                stack.pop_back();
                
                // Calcula a diferença absoluta conforme a regra
                if (n > top_val) {
                    n = n - top_val;
                } else {
                    n = top_val - n;
                }
                
                // A operação de subtração é sucessiva e continua entre o novo n
                // e a caixa imediatamente adjacente ao topo.
            }
            
            // "A caixa vazia não é adicionada à pilha"
            // Se após as subtrações sucessivas n for maior que 0, ele entra na pilha.
            if (n != 0) {
                stack.push_back(n);
            }
        }

        // Formatação da saída conforme especificado: Pilha i: tamanho topo
        cout << "Pilha " << i << ": " << stack.size() << " ";
        
        if (stack.empty()) {
            cout << -1 << "\n";
        } else {
            cout << stack.back() << "\n";
        }
    }

    return 0;
}