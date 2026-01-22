/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int C, N;
    cin >> C >> N;
    
    priority_queue<int, vector<int>, greater<int>> caixas;
    for (int i = 0; i < C; ++i) caixas.push(0);
    
    int clientesEsperando = 0;
    
    for (int i = 0; i < N; ++i) {
        int T, D;
        cin >> T >> D;
        
        int proximoDisponivel = caixas.top();
        caixas.pop();
        
        if (proximoDisponivel > T + 20) {
            clientesEsperando++;
        }
        
        caixas.push(max(proximoDisponivel, T) + D);
    }
    
    cout << clientesEsperando << endl;
    
    return 0;
}
