/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, X;
    cin >> N >> M >> X;
    vector<vector<int>> matriz(N, vector<int>(M));
    vector<int> contagem(M, 0);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> matriz[i][j];
            if (matriz[i][j] == X)
                contagem[j]++;
        }

    int A = *max_element(contagem.begin(), contagem.end());
    
    for (int count : contagem)
        cout << count << " ";
    cout << "\n\n";
    
    vector<vector<int>> grafico(A, vector<int>(M, 0));
    
    for (int j = 0; j < M; j++)
        for (int i = 0; i < contagem[j]; i++)
            grafico[A - 1 - i][j] = 1;

    for (const auto& linha : grafico) {
        for (int val : linha)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}
