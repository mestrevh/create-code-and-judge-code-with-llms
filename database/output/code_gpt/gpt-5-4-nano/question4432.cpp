/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N1;
    if (!(cin >> N1)) return 0;

    vector<string> ids(N1);
    string posStr;
    int L = -1;
    int maxPos = 0;

    for (int i = 0; i < N1; i++) {
        cin >> ids[i];
        if (L == -1) L = (int)ids[i].size();
    }

    int posLen = L / 2;
    int idLen = L - posLen;

    int size = 1u << posLen;

    vector<string> table(size, "");
    vector<char> occ(size, 0);

    for (int i = 0; i < N1; i++) {
        const string &s = ids[i];
        string posPart = s.substr(0, posLen);
        string idPart = s.substr(posLen, idLen);
        int p = 0;
        for (char c : posPart) p = (p << 1) + (c - '0');

        int cur = p;
        while (occ[cur]) cur = (cur + 1) % size;
        occ[cur] = 1;
        table[cur] = idPart;
    }

    int N2;
    cin >> N2;
    for (int i = 0; i < N2; i++) {
        long long x;
        cin >> x;
        if (x < 0 || x >= size || !occ[(int)x]) cout << "Nao tem ninguem";
        else cout << table[(int)x];
        if (i + 1 < N2) cout << "\n";
    }

    return 0;
}