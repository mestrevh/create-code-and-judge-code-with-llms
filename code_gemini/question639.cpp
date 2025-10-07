/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/e do Problema:
O problema pede para minimizar o "Produto Energia × Tempo" (EDP) total para executar uma sequência de `P` programas. Para cada programa, podemos escolher um de `F` níveis de frequência. Cada escolha de frequência para um programa `p` tem um custo de energia `E_p,f` e um tempo de execução `A_p,f`. Mudar de um nível de frequência para outro tem um custo fixo de energia `E` e de tempo `A`.

O objetivo é minimizar `(Energia Total) × (Tempo Total)`. A energia total é a soma da energia de execução de todos os programas mais a soma da energia de todas as mudanças de frequência. O tempo total é calculado de forma análoga.

Como a função de custo `(ΣE) * (ΣT)` não é aditiva (o custo de uma etapa depende das somas acumuladas até então), não podemos usar uma programação dinâmica simples que minimize o custo a cada passo.

A abordagem correta é tratar isso como um problema de caminho mais curto com dois objetivos (minimizar energia e minimizar tempo) em um grafo acíclico dirigido. Os "nós" do nosso DP representam os estados possíveis, e queremos encontrar o conjunto de soluções ótimas de Pareto (ou fronteira de Pareto). Um estado `(E1, T1)` domina outro `(E2, T2)` se `E1 ≤ E2` e `T1 ≤ T2` (com pelo menos uma desigualdade estrita).

A estratégia de programação dinâmica será:
- `dp[p][f]` armazenará um conjunto de pares `(Energia, Tempo)` não dominados, representando os custos totais para executar os primeiros `p` programas, terminando com o programa `p` na frequência `f`.
- Para calcular `dp[p][f]`, consideramos todas as possíveis frequências `k` do programa anterior `p-1`. Para cada par `(e, t)` em `dp[p-1][k]`, calculamos o novo par `(e', t')` adicionando os custos de execução do programa `p` na frequência `f` e os custos da transição de `k` para `f`.
- Todos os novos pares gerados para `dp[p][f]` são combinados em uma lista. Esta lista é então "podada" (pruned) para manter apenas os pares não dominados. A poda consiste em ordenar os pares por energia e, em seguida, iterar, mantendo apenas os pares cujo tempo é estritamente menor que o tempo do último par mantido.
- O estado inicial é o processador na frequência 1 antes do primeiro programa.
- A resposta final é o menor produto `Energia × Tempo` encontrado em todos os pares de todos os conjuntos `dp[P-1][f]`.

Essa abordagem garante que exploremos todas as trocas ótimas entre energia e tempo em cada etapa, encontrando a solução globalmente ótima no final.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct State {
    ll energy;
    ll time;
};

// Função para ordenar os estados, primeiro por energia, depois por tempo.
bool compareStates(const State& a, const State& b) {
    if (a.energy != b.energy) {
        return a.energy < b.energy;
    }
    return a.time < b.time;
}

// Remove estados dominados. Um estado (e2, t2) é dominado por (e1, t1) se e1 <= e2 e t1 <= t2.
// Após ordenar por energia, basta manter os estados cujo tempo é estritamente decrescente.
void prune(vector<State>& states) {
    if (states.empty()) {
        return;
    }
    sort(states.begin(), states.end(), compareStates);
    vector<State> pruned_states;
    pruned_states.push_back(states[0]);
    for (size_t i = 1; i < states.size(); ++i) {
        if (states[i].time < pruned_states.back().time) {
            pruned_states.push_back(states[i]);
        }
    }
    states = pruned_states;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int F, P;
    ll E_change, A_change;

    while (cin >> F >> P >> E_change >> A_change && (F != 0 || P != 0 || E_change != 0 || A_change != 0)) {
        vector<vector<State>> programs(P, vector<State>(F));
        for (int p = 0; p < P; ++p) {
            for (int f = 0; f < F; ++f) {
                cin >> programs[p][f].energy >> programs[p][f].time;
            }
        }

        // dp[f] armazena os pares (energia, tempo) não dominados ao terminar o programa atual na frequência f
        vector<vector<State>> dp(F);

        // Caso base: Primeiro programa (p=0). Processador começa na frequência 1 (índice 0).
        for (int f = 0; f < F; ++f) {
            ll current_E = programs[0][f].energy;
            ll current_T = programs[0][f].time;
            if (f != 0) { // Se a frequência escolhida for diferente da inicial (f=1), há custo de transição.
                current_E += E_change;
                current_T += A_change;
            }
            dp[f].push_back({current_E, current_T});
        }
        
        // DP para os programas restantes
        for (int p = 1; p < P; ++p) {
            vector<vector<State>> next_dp(F);
            for (int j = 0; j < F; ++j) { // Frequência de destino 'j' para o programa 'p'
                vector<State> candidates;
                for (int k = 0; k < F; ++k) { // Frequência de origem 'k' do programa 'p-1'
                    ll trans_E = (j == k) ? 0 : E_change;
                    ll trans_T = (j == k) ? 0 : A_change;
                    
                    for (const auto& prev_state : dp[k]) {
                        candidates.push_back({
                            prev_state.energy + programs[p][j].energy + trans_E,
                            prev_state.time + programs[p][j].time + trans_T
                        });
                    }
                }
                prune(candidates);
                next_dp[j] = candidates;
            }
            dp = next_dp;
        }

        ll min_edp = -1;

        // Encontra o EDP mínimo entre todos os estados finais possíveis
        for (int f = 0; f < F; ++f) {
            for (const auto& state : dp[f]) {
                ll edp = state.energy * state.time;
                if (min_edp == -1 || edp < min_edp) {
                    min_edp = edp;
                }
            }
        }

        cout << min_edp << endl;
    }

    return 0;
}
