/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int M, L, N;
    cin >> M >> L >> N;
    
    vector<string> races;
    vector<int> positionsM, positionsL;
    vector<int> points = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

    for (int i = 0; i < N; ++i) {
        string raceName;
        int posM, posL;
        cin >> raceName >> posM >> posL;
        
        races.push_back(raceName);
        positionsM.push_back(posM);
        positionsL.push_back(posL);
        
        if (posM > 0 && posM <= 10) M += points[posM - 1];
        if (posL > 0 && posL <= 10) L += points[posL - 1];
    }

    string winner;
    int pointDiff = M - L;
    vector<string> aheadRaces;

    if (pointDiff > 0) {
        winner = "Marquinhos";
    } else if (pointDiff < 0) {
        winner = "Luis";
    } else {
        winner = "Marquinhos";
    }

    for (int i = 0; i < N; ++i) {
        if (positionsM[i] < positionsL[i]) {
            aheadRaces.push_back(races[i]);
        }
    }

    if (winner == "Luis" && pointDiff < 0) pointDiff = -pointDiff;

    cout << "O vencedor e " << winner << " com " << abs(pointDiff) << " pontos a mais, ficando a frente em ";
    for (const string &race : aheadRaces) {
        cout << race << "/";
    }
    cout << endl;

    return 0;
}
