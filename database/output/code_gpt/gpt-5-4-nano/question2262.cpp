/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    int I;
    cin >> I;

    vector<int> A(I), B(I);
    for (int i = 0; i < I; i++) cin >> A[i];
    for (int i = 0; i < I; i++) cin >> B[i];

    vector<int> score(N + 1, 0);
    for (int pos = 1; pos <= N; pos++) {
        int dist = abs(pos - (N + 1) / 2);
        score[pos] = dist + 1;
    }

    auto inRange = [&](int p) {
        return p >= 1 && p <= N;
    };

    vector<char> used(N + 1, 0);

    int sasukeScore = 0;
    for (int p : A) {
        if (!inRange(p)) continue;
        if (used[p]) continue;
        used[p] = 1;
        sasukeScore += score[p];
    }

    int itachiScore = 0;
    for (int p : B) {
        if (!inRange(p)) continue;
        if (used[p]) continue;
        used[p] = 1;
        itachiScore += score[p];
    }

    if (sasukeScore > itachiScore) {
        cout << "Sasuke: " << sasukeScore << "\n";
        cout << "Itachi: " << itachiScore << "\n";
        cout << "Sasuke Uchiha";
        if (itachiScore == 0) cout << "\nUm genjutsu desse nivel nao funciona em mim";
    } else if (itachiScore > sasukeScore) {
        cout << "Sasuke: " << sasukeScore << "\n";
        cout << "Itachi: " << itachiScore << "\n";
        cout << "Itachi Uchiha";
        if (sasukeScore == 0) cout << "\nVoce e fraco, lhe falta odio";
    } else {
        cout << "Sasuke: " << sasukeScore << "\n";
        cout << "Itachi: " << itachiScore << "\n";
        cout << "O empate nunca existiu, voce esta preso num genjutsu";
    }

    return 0;
}