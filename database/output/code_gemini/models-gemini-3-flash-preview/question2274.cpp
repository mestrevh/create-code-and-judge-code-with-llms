/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C;
    long long D;
    if (!(cin >> C >> D)) return 0;

    string winnerName = "";
    long long minTime = numeric_limits<long long>::max();

    for (int i = 0; i < C; ++i) {
        string name;
        long long TL, DO, TO;
        cin >> name >> TL >> DO >> TO;

        long long totalSeconds = TL * 60;
        long long obstacleCount = 0;

        // Simulação da corrida através de laço de repetição conforme exigido
        for (long long pos = DO; pos <= D; pos += DO) {
            obstacleCount++;
        }

        totalSeconds += (obstacleCount * TO);

        if (totalSeconds < minTime) {
            minTime = totalSeconds;
            winnerName = name;
        }
    }

    cout << winnerName << " venceu a corrida em " << minTime << " segundos!" << endl;

    return 0;
}