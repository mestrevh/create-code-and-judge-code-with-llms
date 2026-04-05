/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<char> s(6);
    for (int i = 0; i < 6; i++) {
        if (!(cin >> s[i])) return 0;
    }

    vector<int> connected;
    for (int i = 0; i < 6; i++) if (s[i] != 'x') connected.push_back(i);

    int n = (int)connected.size();

    int cut = -1;
    auto colorAt = [&](int idx)->char{ return s[idx]; };

    if (n == 4) {
        bool hasRed = false;
        for (int idx : connected) if (colorAt(idx) == 'r') hasRed = true;
        if (!hasRed) cut = connected[1];
        else {
            if (colorAt(connected.back()) == 'b') cut = connected.back();
            else cut = connected.front();
        }
    } else if (n == 5) {
        if (colorAt(connected[0]) == 'y' && colorAt(connected[1]) == 'y') cut = connected[0];
        else cut = connected[1];
    } else if (n == 6) {
        int greenCount = 0;
        for (int idx : connected) if (colorAt(idx) == 'g') greenCount++;
        if (greenCount == 1) {
            for (int idx : connected) if (colorAt(idx) == 'g') { cut = idx; break; }
        } else {
            cut = connected[4];
        }
    }

    char letter = char('a' + cut);
    cout << "corta " << letter << "\n";
    return 0;
}