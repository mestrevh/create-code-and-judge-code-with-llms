/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, tamX, tamY;
    cin >> N >> tamX >> tamY;
    
    vector<pair<int, int>> coordinates(N);
    for (int i = 0; i < N; i++) {
        cin >> coordinates[i].first >> coordinates[i].second;
    }
    
    vector<vector<int>> board(tamX, vector<int>(tamY));
    for (int i = 0; i < tamX; i++) {
        for (int j = 0; j < tamY; j++) {
            cin >> board[i][j];
        }
    }
    
    int maxScore = 0;

    for (int i = 0; i < N; i++) {
        int x = coordinates[i].first;
        int y = coordinates[i].second;
        vector<int> score(4, 0);
        
        for (int j = 0; j < tamX; j++) {
            if (board[j][y] > 0) score[board[j][y] - 1]++;
        }
        for (int j = 0; j < tamY; j++) {
            if (board[x][j] > 0) score[board[x][j] - 1]++;
        }
        
        maxScore = max(maxScore, *max_element(score.begin(), score.end()));
    }
    
    cout << "A pontuacao da equipe vencedora sera " << maxScore << " ponto(s)!" << endl;
    return 0;
}
