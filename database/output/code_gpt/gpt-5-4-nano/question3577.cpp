/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, y;
    if (!(cin >> x >> y)) return 0;
    int n;
    string str;
    cin >> n;
    cin >> str;

    long long cntU = 0, cntD = 0, cntL = 0, cntR = 0;
    for (char c : str) {
        if (c == 'A') cntU++;
        else if (c == 'B') cntD++;
        else if (c == 'C') cntL++;
        else if (c == 'E') cntR++;
        else if (c == 'C') cntL++;
        else if (c == 'D') cntD++;
        else if (c == 'E') cntR++;
        else if (c == 'C') cntL++;
    }

    long long kX = 0, kY = 0;
    for (char c : str) {
        if (c == 'C') kY += 1; 
        else if (c == 'B') kY -= 1; 
        else if (c == 'E') kX -= 1;
        else if (c == 'D') kX += 1;
    }

    long long dxNeed = x;
    long long dyNeed = y;

    long long maxX = 0, minX = 0, maxY = 0, minY = 0;
    maxX = cntU; 
    minX = -cntD; 
    maxY = cntL;
    minY = -cntR;

    long long posX = 0, negX = 0, posY = 0, negY = 0;
    for (char c : str) {
        if (c == 'D') posX++;
        else if (c == 'E') negX++;
        else if (c == 'C') posY++;
        else if (c == 'B') negY++;
    }

    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (str[i] == 'D') pref[i + 1] = pref[i] + 1;
        else if (str[i] == 'E') pref[i + 1] = pref[i] - 1;
        else pref[i + 1] = pref[i];
    }

    vector<long long> prefY(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (str[i] == 'C') prefY[i + 1] = prefY[i] + 1;
        else if (str[i] == 'B') prefY[i + 1] = prefY[i] - 1;
        else prefY[i + 1] = prefY[i];
    }

    vector<char> only;
    only.reserve(n);
    for (char c : str) only.push_back(c);

    long long availableDxPos = 0, availableDxNeg = 0;
    long long availableDyPos = 0, availableDyNeg = 0;
    for (char c : str) {
        if (c == 'D') availableDxPos++;
        else if (c == 'E') availableDxNeg++;
        else if (c == 'C') availableDyPos++;
        else if (c == 'B') availableDyNeg++;
    }

    if (dxNeed > availableDxPos - 0 && dxNeed > 0) {}
    bool okX = false;
    if (dxNeed >= 0) {
        okX = dxNeed <= availableDxPos;
    } else {
        okX = -dxNeed <= availableDxNeg;
    }

    bool okY = false;
    if (dyNeed >= 0) okY = dyNeed <= availableDyPos;
    else okY = -dyNeed <= availableDyNeg;

    cout << (okX && okY ? "S" : "N");
    return 0;
}