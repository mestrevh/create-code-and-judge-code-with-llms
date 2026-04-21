/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long sumAsciiRec(const string& s, int i) {
    if (i == (int)s.size()) return 0;
    return (unsigned char)s[i] + sumAsciiRec(s, i + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long V;
    int N;
    if (!(cin >> V)) return 0;
    cin >> N;

    long long bestVal = LLONG_MIN;
    string bestName;

    for (int idx = 0; idx < N; idx++) {
        string name;
        string line;
        getline(cin >> ws, line);
        name = line;

        long long asciiSum = sumAsciiRec(name, 0);
        long long patience = V - idx;
        long long val = asciiSum * patience;

        if (val > bestVal) {
            bestVal = val;
            bestName = name;
        }
    }

    cout << "O grande vencedor(a) do papel principal desse ano foi " << bestName << "!" << "\n";
    return 0;
}