/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int B, M, caso = 1;
    while (cin >> B >> M, B || M) {
        vector<string> resultados(B, "?");
        vector<vector<char>> votos(M, vector<char>(B + 1, ' '));
        vector<int> contagem(B + 1, 0);
        
        for (int i = 0; i < M; ++i) {
            int k;
            cin >> k;
            for (int j = 0; j < k; ++j) {
                int projeto;
                char voto;
                cin >> projeto >> voto;
                votos[i][projeto] = voto;
            }
        }
        
        for (int projeto = 1; projeto <= B; ++projeto) {
            int sim = 0, nao = 0;
            for (int ministro = 0; ministro < M; ++ministro) {
                if (votos[ministro][projeto] == 's') sim++;
                else if (votos[ministro][projeto] == 'n') nao++;
            }
            
            if (sim + nao >= (M + 1) / 2) {
                resultados[projeto - 1] = (sim > nao) ? 'S' : 'N';
            }
        }

        cout << "Caso " << caso++ << ": ";
        for (char resultado : resultados) {
            cout << resultado;
        }
        cout << endl;
    }
    return 0;
}
