/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, C;
    cin >> N >> M >> C;
    vector<pair<int,int>> intervals(M);
    for(int i = 0; i < M; i++) {
        cin >> intervals[i].first >> intervals[i].second;
        intervals[i].first--;
        intervals[i].second--;
    }
    
    // Para cada posição, marcar quais intervalos cobrem ela
    vector<vector<int>> covers(N);
    for(int i = 0; i < M; ++i)
        for(int j = intervals[i].first; j <= intervals[i].second; ++j)
            covers[j].push_back(i);

    // Grupos de indistinguibilidade
    // Dois servidores (posições) são indistinguíveis se sempre são cobertos pelo mesmo conjunto de intervalos
    map<vector<int>, vector<int>> cls;
    for(int i = 0; i < N; ++i)
        sort(covers[i].begin(), covers[i].end());
    for(int i = 0; i < N; ++i)
        cls[covers[i]].push_back(i);
    
    int K = cls.size();
    // Número de classes de indistinguibilidade K
    // Para cada classe, a cor final depende dos últimos intervalos a cobrir todos elementos do grupo
    // O resultado é C^K

    ll ans = 1;
    for(int i = 0; i < K; ++i)
        ans = (ans * C) % MOD;
    cout << ans << '\n';
    return 0;
}
