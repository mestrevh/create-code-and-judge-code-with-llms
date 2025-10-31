/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

int N, M, C;
vector<pair<int,int>> intervals;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> C;
    intervals.resize(M);
    for (int i = 0; i < M; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
        intervals[i].first--;
        intervals[i].second--;
    }

    // Para cada posição, guarda quais operações a cobrem
    vector<vector<int>> covered(N);
    for (int i = 0; i < M; ++i) {
        for (int j = intervals[i].first; j <= intervals[i].second; ++j) {
            covered[j].push_back(i);
        }
    }

    // Para cada combinação de última operação feita em cada posição, gera todas as possíveis configurações finais distintas
    // Usa set para evitar duplicidade

    // Para cada posição, a última operação que altera o valor nela determina sua cor final
    // Podemos fazer: para cada "mapeamento" de operação -> cor, permutamos todas as ordens e testamos a configuração?
    // Mas isso é inviável para N e M grandes, precisamos do insight é: o estado final só depende da operação que é aplicada por último em cada posição

    // Portanto, cada vector<int> "ult_op" de N posições [p0 .. p(N-1)], 
    // onde ult_op[i] é o índice da operação aplicada por último sobre o i (menor índice de op que cobre a posição quando processadas em ordem reversa na permutação)
    // Cada atribuição de qual operação é a última a cobrir cada posição, correspondente a uma topological sorting (senão viola as ordens dos intervalos sobreposições)
    // O número de colorings distintos é equivalente ao número de formas de pintar o "graph" gerado, que é igual ao número de formas de colorir as regiões finais distintas

    // A ideia é: cada posição precisa ter a cor da última operação a afetá-la, logo não importa a ordem das operações fora das últimas sobre cada posição
    // Com os intervalos, ao aplicar ESSAS M operações, resulta em um mapeamento de: para cada operação, o intervalo coberto, e a cor, aplicada por último
    // Se dois intervalos A e B têm interseção, para que a cor final seja diferente em posições em comum, a última operação nessas posições têm que ser diferentes

    // O processo resulta em "corte de segmentos": o mínimo número de segmentos de posições de [1,N], tal que todo intervalo está partido em subsegmentos sem sobreposição extra
    // O número de configurações finais distintas é C^{#de segmentos distintos}

    // Para cada ponto onde começa ou termina algum intervalo, split nos cortes
    set<int> cuts{0,N};
    for (auto &[l,r]: intervals) {
        cuts.insert(l);
        cuts.insert(r+1);
    }
    vector<pair<int,int>> segs;
    int last = -1;
    for (int p: cuts) {
        if (last != -1 && p > last)
            segs.push_back({last, p-1});
        last = p;
    }
    // Cada segmento precisa ser colorido, e para cada segmento só importa a cor final
    // A configuração final é definida pela cor de cada segmento; não há restrição de cores entre segmentos contíguos
    // Portanto, resposta = C^(qtd de segmentos)

    int64_t ans = 1;
    for (int i = 0; i < (int)segs.size(); ++i) ans = ans * C % MOD;
    cout << ans << '\n';
    return 0;
}
