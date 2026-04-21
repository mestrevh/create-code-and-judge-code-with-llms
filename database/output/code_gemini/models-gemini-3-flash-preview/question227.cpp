/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problema: Paciência em linha (Accordion Solitaire)
 * Especialista: Grande Mestre em Programação Competitiva
 * Estratégia: Simulação baseada em regras de prioridade (Leftmost Card first, 3-jump before 1-jump).
 */

inline bool match(const string& a, const string& b) {
    // Cartas combinam se possuem a mesma classe (primeiro caractere) ou mesmo naipe (segundo caractere)
    return (a[0] == b[0] || a[1] == b[1]);
}

int main() {
    // Otimização de I/O padrão C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    // O loop continua enquanto houver cartas na entrada e o primeiro caractere não for '#'
    while (cin >> s && s != "#") {
        // Armazena as pilhas de cartas (cada pilha é um vector para fácil acesso ao topo)
        vector<vector<string>> piles;
        piles.reserve(52);
        
        // Lê a primeira carta já capturada no while e as 51 restantes de uma rodada (52 cartas totais)
        vector<string> first_p;
        first_p.push_back(s);
        piles.push_back(first_p);
        
        for (int i = 1; i < 52; ++i) {
            if (!(cin >> s)) break;
            vector<string> p;
            p.push_back(s);
            piles.push_back(p);
        }

        bool moved = true;
        while (moved) {
            moved = false;
            // Varredura da esquerda para a direita para encontrar o movimento da carta mais à esquerda possível
            for (int i = 1; i < (int)piles.size(); ++i) {
                int target = -1;
                
                // Prioridade 1: Movimento para a terceira pilha à esquerda (salto de 3)
                if (i >= 3 && match(piles[i].back(), piles[i - 3].back())) {
                    target = i - 3;
                } 
                // Prioridade 2: Movimento para a pilha vizinha à esquerda (salto de 1)
                else if (match(piles[i].back(), piles[i - 1].back())) {
                    target = i - 1;
                }

                if (target != -1) {
                    // Executa o movimento movendo o topo da pilha atual para o topo da pilha destino
                    piles[target].push_back(piles[i].back());
                    piles[i].pop_back();
                    
                    // Se a pilha original ficar vazia, remove o espaço e compacta a linha
                    if (piles[i].empty()) {
                        piles.erase(piles.begin() + i);
                    }
                    
                    // Após qualquer movimento, reinicia a busca a partir da esquerda (regra do "mais à esquerda")
                    moved = true;
                    break;
                }
            }
        }

        // Formatação de saída conforme especificado
        if (piles.size() == 1) {
            cout << "1 pilha sobrando: 52" << endl;
        } else {
            cout << piles.size() << " pilhas sobrando:";
            for (int i = 0; i < (int)piles.size(); ++i) {
                cout << " " << (int)piles[i].size();
            }
            cout << endl;
        }
    }

    return 0;
}