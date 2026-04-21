/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<string> s(N);
    vector<char> D(N);
    for (int i = 0; i < N; i++) {
        cin >> D[i] >> s[i];
    }
    string P;
    cin >> P;

    int m = (int)P.size();
    string circle;
    circle.reserve(N * 12);

    for (int i = 0; i < N; i++) {
        const string& a = s[i];
        if (D[i] == 'd') {
            circle += a.substr(0, 6);
            circle += a.substr(6);
        } else {
            circle += string(a.rbegin() + (a.size() - 1 - 0), a.rend() - 6);
            int L = 12;
            int leftStart = L - 1 - 6; 
        }
    }

    circle.clear();
    for (int i = 0; i < N; i++) {
        const string &a = s[i];
        string halfL = a.substr(0, 6);
        string halfR = a.substr(6, 6);

        if (D[i] == 'd') {
            circle += halfL;
            circle += halfR;
        } else {
            for (int k = 5; k >= 0; k--) circle.push_back(halfL[k]);
            for (int k = 11; k >= 6; k--) circle.push_back(a[k]);
        }
    }

    string doubled = circle + circle;

    vector<int> lps(m, 0);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && P[i] != P[j]) j = lps[j - 1];
        if (P[i] == P[j]) j++;
        lps[i] = j;
    }

    long long cnt = 0;
    int j = 0;
    int L = (int)doubled.size();
    for (int i = 0; i < L; i++) {
        while (j > 0 && doubled[i] != P[j]) j = lps[j - 1];
        if (doubled[i] == P[j]) j++;
        if (j == m) {
            int start = i - m + 1;
            if (start < (int)circle.size()) cnt++;
            j = lps[j - 1];
        }
    }

    cout << P << cnt;
    return 0;
}