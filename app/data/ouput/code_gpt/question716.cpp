/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
    int C;
    cin >> C;
    
    for (int caso = 0; caso < C; caso++) {
        int N, M, K, P, A;
        cin >> N >> M >> K >> P >> A;

        vector<int> bolas(N);
        for (int i = 0; i < N; i++)
            cin >> bolas[i];

        vector<vector<int>> jogadores(P, vector<int>(K));
        for (int i = 0; i < P; i++)
            for (int j = 0; j < K; j++)
                cin >> jogadores[i][j];

        sort(bolas.begin(), bolas.end());

        unordered_map<int, int> posicao;
        for (int i = 0; i < N; i++)
            posicao[bolas[i]] = i + 1; // usando 1-index para as posições

        set<int> vencedores;
        
        for (int j = 0; j < P; j++) {
            int pontuacao = 0;
            for (int k = 0; k < K; k++) {
                pontuacao += posicao[jogadores[j][k]];
            }
            if (pontuacao == A)
                vencedores.insert(j);
        }

        cout << "caso " << caso << ":";
        for (int v : vencedores)
            cout << " " << v;
        cout << "\n\n";
    }

    return 0;
}
