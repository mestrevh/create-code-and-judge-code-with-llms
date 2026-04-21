/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isValid(const string& s) {
    int atPos = -1;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '@') {
            if (atPos != -1) return false;
            atPos = i;
        }
    }
    if (atPos == -1) return false;
    if (atPos == 0) return false;

    int firstDot = -1, secondDot = -1;
    int dotCount = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '.') {
            dotCount++;
            if (dotCount == 1) firstDot = i;
            else if (dotCount == 2) secondDot = i;
            else return false;
        }
    }
    if (dotCount != 2) return false;

    if (firstDot > secondDot) swap(firstDot, secondDot);

    if (firstDot < atPos || secondDot < atPos) return false;

    if (firstDot - atPos - 1 < 1) return false;
    if (secondDot - firstDot - 1 < 1) return false;
    if ((int)s.size() - secondDot - 1 < 1) return false;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (cin >> line) {
        if (line == "sair") break;
        cout << (isValid(line) ? "certo" : "errado") << "\n";
    }
    return 0;
}