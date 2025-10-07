/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, I;
    cin >> N;
    cin >> I;

    vector<int> sasuke(I), itachi(I);
    for (int i = 0; i < I; ++i) cin >> sasuke[i];
    for (int i = 0; i < I; ++i) cin >> itachi[i];

    vector<int> points(N);
    for (int i = 0; i < (N + 1) / 2; ++i) {
        points[i] = points[N - 1 - i] = i + 1;
    }

    set<int> sasukeScores, itachiScores;
    for (int x : sasuke) {
        if (x >= 1 && x <= N) sasukeScores.insert(points[x - 1]);
    }
    for (int x : itachi) {
        if (x >= 1 && x <= N) itachiScores.insert(points[x - 1]);
    }

    int sasukePoints = 0, itachiPoints = 0;
    for (int score : sasukeScores) sasukePoints += score;
    for (int score : itachiScores) itachiPoints += score;

    cout << "Sasuke: " << sasukePoints << endl;
    cout << "Itachi: " << itachiPoints << endl;

    if (sasukePoints > itachiPoints) {
        cout << "Sasuke Uchiha" << endl;
    } else if (itachiPoints > sasukePoints) {
        cout << "Itachi Uchiha" << endl;
    } else {
        cout << "O empate nunca existiu, voce esta preso num genjutsu" << endl;
    }

    if (sasukePoints == 0 && itachiPoints > 0) {
        cout << "Voce e fraco, lhe falta odio" << endl;
    } else if (itachiPoints == 0 && sasukePoints > 0) {
        cout << "Um genjutsu desse nivel nao funciona em mim" << endl;
    } else if (sasukePoints == 0 && itachiPoints == 0) {
        cout << "Os Uchihas nem sao tao bons mesmo" << endl;
    }

    return 0;
}
