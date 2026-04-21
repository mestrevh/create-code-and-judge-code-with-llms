/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ptsF = 0;
    int ptsC = 0;
    int winsF = 0;
    int winsC = 0;

    for (int i = 0; i < 5; ++i) {
        char winner;
        cin >> winner;
        if (winner == 'f') winsF++;
        else if (winner == 'c') winsC++;
    }

    if (winsF > winsC) ptsF += 40;
    else if (winsC > winsF) ptsC += 40;

    int pedroEscalado, yuriEscalado;
    cin >> pedroEscalado >> yuriEscalado;
    if (pedroEscalado == 1) ptsF += 20;
    if (yuriEscalado == 1) ptsC += 20;

    int golsF, golsC;
    cin >> golsF >> golsC;
    if (golsF > golsC) ptsF += 15;
    else if (golsC > golsF) ptsC += 15;

    double avgF, avgC;
    cin >> avgF >> avgC;
    if (avgF >= 2.0) ptsF += 10;
    if (avgC >= 2.0) ptsC += 10;

    if (ptsF > ptsC) {
        cout << "Luiza tem mais chances de comer o brownie" << "\n";
        cout << "Pontos:" << ptsF << endl;
    } else {
        cout << "Pedro tem mais chances de comer o brownie" << "\n";
        cout << "Pontos:" << ptsC << endl;
    }

    return 0;
}