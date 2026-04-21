/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int get_note_val(const string& s) {
    int note = 0;
    if (s[0] == 'C') note = 0;
    else if (s[0] == 'D') note = 2;
    else if (s[0] == 'E') note = 4;
    else if (s[0] == 'F') note = 5;
    else if (s[0] == 'G') note = 7;
    else if (s[0] == 'A') note = 9;
    else if (s[0] == 'B') note = 11;
    if (s.length() > 1) {
        if (s[1] == '#') note = (note + 1) % 12;
        else if (s[1] == 'b') note = (note + 11) % 12;
    }
    return note;
}

bool kmp_search(const vector<int>& S, const vector<int>& P) {
    int n = S.size();
    int m = P.size();
    if (m == 0) return true;
    vector<int> pi(m);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && P[i] != P[j]) j = pi[j - 1];
        if (P[i] == P[j]) j++;
        pi[i] = j;
    }
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && S[i] != P[j]) j = pi[j - 1];
        if (S[i] == P[j]) j++;
        if (j == m) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M, T;
    while (cin >> M >> T && (M || T)) {
        vector<int> m_notes(M);
        string s;
        for (int i = 0; i < M; i++) {
            cin >> s;
            m_notes[i] = get_note_val(s);
        }
        vector<int> t_notes(T);
        for (int i = 0; i < T; i++) {
            cin >> s;
            t_notes[i] = get_note_val(s);
        }
        if (T == 1) {
            cout << "S\n";
            continue;
        }
        vector<int> S_intervals(M - 1);
        for (int i = 0; i < M - 1; i++) {
            S_intervals[i] = (m_notes[i + 1] - m_notes[i] + 12) % 12;
        }
        vector<int> P_intervals(T - 1);
        for (int i = 0; i < T - 1; i++) {
            P_intervals[i] = (t_notes[i + 1] - t_notes[i] + 12) % 12;
        }
        if (kmp_search(S_intervals, P_intervals)) {
            cout << "S\n";
        } else {
            cout << "N\n";
        }
    }
    return 0;
}