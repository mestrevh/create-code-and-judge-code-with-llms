/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// Checa se é possível organizar todas as peças em uma formação válida
bool verifica_domino(const vector<pair<int, int>>& pecas) {
    int grau[7] = {0};
    vector<int> g[7];
    bool visitado[7] = {0};
    int total = pecas.size();

    for (auto& p : pecas) {
        grau[p.first]++;
        grau[p.second]++;
        g[p.first].push_back(p.second);
        g[p.second].push_back(p.first);
    }

    // Encontra ponto de início para dfs
    int inicio = -1;
    for(int i=0; i<7; i++) if(g[i].size()) { inicio = i; break; }
    if(inicio == -1) return true; // sem peças

    // dfs para ver se é conexo
    vector<bool> vis(7,false);
    vector<int> stack{inicio};
    vis[inicio] = true;
    int cnt = 1;
    while(!stack.empty()) {
        int u = stack.back(); stack.pop_back();
        for(int v: g[u]) {
            if(!vis[v]) { 
                vis[v]=true;
                cnt++;
                stack.push_back(v);
            }
        }
    }
    // conta vértices envolvidos
    int n_vertex=0;
    for(int i=0;i<7;i++) if(g[i].size()) n_vertex++;
    if(cnt != n_vertex) return false;

    // verifica grau ímpar
    int impar=0;
    for(int x=0;x<7;x++) if(grau[x]%2) impar++;
    if(impar == 0 || impar == 2) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, teste=1;
    while (cin >> N, N) {
        vector<pair<int,int>> pecas;
        for(int i=0;i<N;i++) {
            int a,b; cin >> a >> b;
            pecas.emplace_back(a,b);
        }
        cout << "Teste " << teste++ << '\n';
        cout << (verifica_domino(pecas) ? "sim" : "nao") << '\n';
        cout << '\n';
    }
    return 0;
}
