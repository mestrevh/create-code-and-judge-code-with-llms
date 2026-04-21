/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Signal {
    int amp;
    int freq;
    double energy;
    bool periodic;
};

static int scorePair(const Signal& a, const Signal& b) { // a vs b
    int score = 0;
    if (a.amp > b.amp) score += 1;
    if (a.freq != b.freq) {
        int big = max(a.freq, b.freq);
        int small = min(a.freq, b.freq);
        if (big % small == 0) {
            if (a.freq == big) score += 1;
        } else {
        }
    } else {
        score += 1; // same frequency both get point; in pairwise scoring from one side, count as +1
    }
    if (a.energy > b.energy) score += 1;
    if (a.energy == b.energy) {
    } else {
    }
    if (a.periodic && !b.periodic) score += 1;
    if (a.periodic == b.periodic) {
        if (a.periodic && b.periodic) {
        }
    }
    return score;
}

static int scoreFromOneToOther(const Signal& a, const Signal& b) {
    int s = 0;
    if (a.amp > b.amp) s++;
    if (a.freq == b.freq) s++;
    else {
        int big = max(a.freq, b.freq);
        int small = min(a.freq, b.freq);
        if (big % small == 0 && a.freq == big) s++;
    }
    if (a.energy > b.energy) s++;
    if (a.periodic && !b.periodic) s++;
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Signal princess;
    bool hasPrincess = false;

    vector<Signal> enemies;

    while (true) {
        int x, y;
        double z;
        string w;
        if (!(cin >> x >> y >> z >> w)) break;
        Signal s;
        s.amp = x;
        s.freq = y;
        s.energy = z;
        s.periodic = (w == "TRUE");
        if (!hasPrincess) {
            princess = s;
            hasPrincess = true;
        } else {
            enemies.push_back(s);
        }
    }

    int n = (int)enemies.size();
    vector<int> pointsPrincess(n, 0);
    vector<int> pointsEnemy(n, 0);
    vector<bool> princessWon(n, false);

    int bestPrincessScore = 0;
    for (int i = 0; i < n; i++) {
        const Signal& e = enemies[i];
        int sp = 0, se = 0;

        if (princess.amp > e.amp) sp++;
        else if (princess.amp < e.amp) se++;

        if (princess.freq == e.freq) {
            sp++;
            se++;
        } else {
            int big = max(princess.freq, e.freq);
            int small = min(princess.freq, e.freq);
            if (big % small == 0) {
                if (princess.freq == big) sp++;
                else se++;
            }
        }

        if (princess.energy > e.energy) sp++;
        else if (princess.energy < e.energy) se++;

        if (princess.periodic && !e.periodic) sp++;
        else if (!princess.periodic && e.periodic) se++;

        pointsPrincess[i] = sp;
        pointsEnemy[i] = se;
        if (sp > se) princessWon[i] = true;

        bestPrincessScore = max(bestPrincessScore, sp);
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);

    auto cmp = [&](int i, int j) {
        if (pointsEnemy[i] != pointsEnemy[j]) return pointsEnemy[i] > pointsEnemy[j]; 
        if (pointsPrincess[i] != pointsPrincess[j]) return pointsPrincess[i] < pointsPrincess[j]; 
        if (enemies[i].amp != enemies[j].amp) return enemies[i].amp > enemies[j].amp;
        if (enemies[i].freq != enemies[j].freq) return enemies[i].freq > enemies[j].freq;
        return enemies[i].energy > enemies[j].energy;
    };

    vector<int> rankEnemies(n);
    for (int idx : ord) {
        rankEnemies[idx] = 0;
    }

    sort(ord.begin(), ord.end(), [&](int i, int j){
        if (pointsEnemy[i] != pointsEnemy[j]) return pointsEnemy[i] > pointsEnemy[j];
        return i < j;
    });

    bool flawless = true;
    for (int i = 0; i < n; i++) {
        if (!princessWon[i]) flawless = false;
    }

    vector<int> wonList;
    for (int i = 0; i < n; i++) if (princessWon[i]) wonList.push_back(i);

    double eps = 1e-9;
    auto energyEq = [&](double a, double b){ return fabs(a-b) < eps; };

    cout.setf(std::ios::fixed); 
    cout << setprecision(2);

    Signal first = princess;
    cout << first.amp << ' ' << first.freq << ' ' << first.energy << ' ' << bestPrincessScore;

    if (!wonList.empty()) {
        vector<int> indicesInSorted;
        for (int idx : ord) {
            if (princessWon[idx]) indicesInSorted.push_back(idx);
        }
        cout << " WINNER ( ";
        for (int k = 0; k < (int)indicesInSorted.size(); k++) {
            int idx = indicesInSorted[k];
            int posInSorted = (int)indicesInSorted.size(); 
            (void)posInSorted;
        }
        for (int t = 0; t < (int)indicesInSorted.size(); t++) {
            int idx = indicesInSorted[t];
            int originalIndex = idx;
            int orderRank = (int)(find(ord.begin(), ord.end(), originalIndex) - ord.begin()) + 1;
            int rankPos = orderRank;
            if (t) cout << ' ';
            cout << rankPos;
        }
        cout << " )";
    } else {
    }

    cout << "\n---\n";

    vector<int> wonInSorted;
    vector<bool> willPrintWinner(n,false);
    for (int i = 0; i < n; i++) {
        int sp = pointsPrincess[i], se = pointsEnemy[i];
        willPrintWinner[i] = (se >= sp && !princessWon[i] ? true : (!princessWon[i] && sp==se)); 
    }

    for (int k = 0; k < n; k++) {
        int i = ord[k];
        const Signal& e = enemies[i];
        int pen = pointsEnemy[i];
        cout << e.amp << ' ' << e.freq << ' ' << e.energy << ' ' << pen;
        if (!princessWon[i]) cout << " WINNER";
        cout << "\n";
    }

    if (flawless) cout << "FLAWLESS VICTORY!";

    return 0;
}