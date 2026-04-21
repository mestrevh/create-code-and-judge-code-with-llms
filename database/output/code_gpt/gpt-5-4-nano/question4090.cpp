/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string w;
    vector<char> wins;
    for (int i = 0; i < 5; i++) {
        if (!(cin >> w)) return 0;
        wins.push_back(w[0]);
    }

    int pedEsc = 0, yuriEsc = 0;
    cin >> pedEsc >> yuriEsc;

    long long golsFlamengo = 0, golsCorinthians = 0;
    cin >> golsFlamengo >> golsCorinthians;

    double mediaFlamengo = 0.0, mediaCorinthians = 0.0;
    cin >> mediaFlamengo >> mediaCorinthians;

    int vFlamengo = 0, vCorinthians = 0;
    for (char c : wins) {
        if (c == 'f') vFlamengo++;
        else if (c == 'c') vCorinthians++;
    }

    long long pontosFlamengo = 0, pontosCorinthians = 0;

    if (vFlamengo > vCorinthians) pontosFlamengo += 40;
    if (vCorinthians > vFlamengo) pontosCorinthians += 40;

    if (pedEsc == 1) pontosFlamengo += 20;
    if (yuriEsc == 1) pontosCorinthians += 20;

    if (golsFlamengo > golsCorinthians) pontosFlamengo += 15;
    if (golsCorinthians > golsFlamengo) pontosCorinthians += 15;

    bool acimaFlamengo = mediaFlamengo >= 2.0;
    bool acimaCorinthians = mediaCorinthians >= 2.0;

    if (acimaFlamengo && acimaCorinthians) {
        pontosFlamengo += 10;
        pontosCorinthians += 10;
    } else if (acimaFlamengo) {
        pontosFlamengo += 10;
    } else if (acimaCorinthians) {
        pontosCorinthians += 10;
    }

    if (pontosFlamengo > pontosCorinthians) {
        cout << "Luiza tem mais chances de comer o brownie\n";
        cout << "Pontos:" << pontosFlamengo;
    } else {
        cout << "Pedro tem mais chances de comer o brownie\n";
        cout << "Pontos:" << pontosCorinthians;
    }

    return 0;
}