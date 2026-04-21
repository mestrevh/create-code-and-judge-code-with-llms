/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    double sumA = 0, sumB = 0, sumC = 0;
    int cntA = 0, cntB = 0, cntC = 0;

    for (int i = 0; i < n; ++i) {
        char team;
        double power;
        cin >> team >> power;
        if (team == 'A') {
            sumA += power;
            cntA++;
        } else if (team == 'B') {
            sumB += power;
            cntB++;
        } else if (team == 'C') {
            sumC += power;
            cntC++;
        }
    }

    double meanA = (cntA > 0) ? (sumA / cntA) : -2e18;
    double meanB = (cntB > 0) ? (sumB / cntB) : -2e18;
    double meanC = (cntC > 0) ? (sumC / cntC) : -2e18;

    char chosenTeam;
    double chosenMean;

    if (meanA >= meanB && meanA >= meanC) {
        chosenTeam = 'A';
        chosenMean = meanA;
    } else if (meanB >= meanC) {
        chosenTeam = 'B';
        chosenMean = meanB;
    } else {
        chosenTeam = 'C';
        chosenMean = meanC;
    }

    cout << "A equipe escolhida foi a " << chosenTeam << ", com media de: " << fixed << setprecision(2) << chosenMean << endl;

    return 0;
}