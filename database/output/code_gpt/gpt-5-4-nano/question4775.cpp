/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> names(n);
    vector<double> bets(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i] >> bets[i];
    }

    if (n == 1) {
        cout << "Jogar com uma pessoa só nem tem graça...\n";
        return 0;
    }

    double totalBet = 0.0;
    for (double b : bets) totalBet += b;

    bool hasAzeik = false, hasOdnanref = false;
    for (auto &nm : names) {
        if (nm == "Azeik") hasAzeik = true;
        if (nm == "Odnanref") hasOdnanref = true;
    }

    if (hasAzeik) {
        cout << "Hoje, quem vai jogar Azeik palavras é ";
        for (int i = 0; i < n; i++) {
            if (i) cout << ", ";
            cout << names[i];
        }
        cout << ".\n";
        cout << "Tem muito dinheiro em jogo, quem vai levar a bolada de " << fixed << setprecision(2) << totalBet << " reais?\n";
        cout << "Azeik todo mundo sabe que você vai ganhar, não precisa jogar, tome o dinheiro e vá jogar no tigrinho.\n";
        return 0;
    }

    if (hasOdnanref) {
        cout << "Hoje, quem vai jogar Azeik palavras é ";
        for (int i = 0; i < n; i++) {
            if (i) cout << ", ";
            cout << names[i];
        }
        cout << ".\n";
        cout << "Tem muito dinheiro em jogo, quem vai levar a bolada de " << fixed << setprecision(2) << totalBet << " reais?\n";
        cout << "Odnanref está aqui nem vale a pena jogar, esse cara atrapalha tudo!\n";
        return 0;
    }

    int X;
    cin >> X;

    vector<bool> alive(n, true);
    vector<long long> score(n, 0);
    vector<long long> bestSingle(n, 0);

    int aliveCount = n;

    for (int round = 0; round < X; round++) {
        if (aliveCount <= 1) break;

        string ref;
        cin >> ref;

        for (int i = 0; i < n; i++) {
            string chosen;
            cin >> chosen;

            if (!alive[i]) continue;

            if (!chosen.empty() && !ref.empty() && chosen[0] == ref[0]) {
                long long add = (long long)chosen.size();
                if (chosen == ref) add *= 2;
                score[i] += add;
                if (add > bestSingle[i]) bestSingle[i] = add;
            } else {
                alive[i] = false;
                aliveCount--;
            }
        }
    }

    int winner = -1;
    long long maxScore = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        if (!alive[i]) continue;
        if (score[i] > maxScore) {
            maxScore = score[i];
            winner = i;
        } else if (score[i] == maxScore) {
            if (names[i] < names[winner]) winner = i;
        }
    }

    if (winner == -1) {
        long long globalMax = LLONG_MIN;
        int globalWinner = 0;
        for (int i = 0; i < n; i++) {
            if (score[i] > globalMax) {
                globalMax = score[i];
                globalWinner = i;
            } else if (score[i] == globalMax && names[i] < names[globalWinner]) {
                globalWinner = i;
            }
        }
        winner = globalWinner;
    }

    long long winnerScore = score[winner];
    long long maxSingle = bestSingle[winner];

    vector<string> matchedRefs;
    cin.clear();

    cin.seekg(0, ios::beg);
    int n2;
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        string nm;
        double b;
        cin >> nm >> b;
    }
    int X2;
    cin >> X2;

    alive.assign(n2, true);
    aliveCount = n2;
    score.assign(n2, 0);
    bestSingle.assign(n2, 0);

    for (int round = 0; round < X2; round++) {
        if (aliveCount <= 1) break;
        string ref;
        cin >> ref;

        bool aliveBefore = alive[winner];

        for (int i = 0; i < n2; i++) {
            string chosen;
            cin >> chosen;

            if (!alive[i]) continue;

            if (!chosen.empty() && !ref.empty() && chosen[0] == ref[0]) {
                long long add = (long long)chosen.size();
                if (chosen == ref) add *= 2;
                score[i] += add;
                if (add > bestSingle[i]) bestSingle[i] = add;
            } else {
                alive[i] = false;
                aliveCount--;
            }
        }

        if (aliveBefore && alive[winner]) {
            matchedRefs.push_back(ref);
        } else if (!aliveBefore) {
        }
    }

    int tieWinnerScoreCount = 0;
    for (int i = 0; i < n; i++) if (score[i] == winnerScore) tieWinnerScoreCount++;

    cout << "Hoje, quem vai jogar Azeik palavras é ";
    for (int i = 0; i < n; i++) {
        if (i) cout << ", ";
        cout << names[i];
    }
    cout << ".\n";
    cout << "Tem muito dinheiro em jogo, quem vai levar a bolada de " << fixed << setprecision(2) << totalBet << " reais?\n";

    cout << "Temos um vencedor...\n";
    cout << names[winner] << " venceu e levou a bolada de " << fixed << setprecision(2) << totalBet << " reais para casa!\n";
    cout << "E não para por aí, " << names[winner] << " fez uma pontuação histórica de " << winnerScore << " pontos, conseguindo um total de " << maxSingle << " pontos numa só rodada!\n";

    if (!matchedRefs.empty()) {
        cout << "Impressionante, " << names[winner] << " ainda conseguiu acertar essas palavras de referência: ";
        for (size_t i = 0; i < matchedRefs.size(); i++) {
            if (i) cout << ", ";
            cout << matchedRefs[i];
        }
        cout << "!\n";
    }

    if (tieWinnerScoreCount > 1) {
        cout << "E mesmo com tudo isso, foi apertado. Agradeça a seus pais, que foram eles que fizeram você ganhar esse dinheiro.\n";
    }

    return 0;
}