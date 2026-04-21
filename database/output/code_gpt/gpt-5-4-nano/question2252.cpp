/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string trim(const string& s) {
    size_t b = 0;
    while (b < s.size() && isspace((unsigned char)s[b])) b++;
    size_t e = s.size();
    while (e > b && isspace((unsigned char)s[e-1])) e--;
    return s.substr(b, e-b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    string line;
    getline(cin, line);

    vector<pair<string, double>> alunos;
    alunos.reserve(N);

    for (int i = 0; i < N; i++) {
        getline(cin, line);
        while (line.size() == 0 && !cin.eof()) getline(cin, line);

        vector<string> parts;
        string cur;
        for (char ch : line) {
            if (ch == ',') {
                parts.push_back(cur);
                cur.clear();
            } else {
                cur.push_back(ch);
            }
        }
        parts.push_back(cur);

        for (auto &p : parts) p = trim(p);
        string nome = parts.empty() ? "" : parts[0];

        double sum = 0.0;
        int cnt = 0;
        for (int j = 1; j < (int)parts.size() && cnt < 4; j++) {
            if (parts[j].empty()) continue;
            sum += stod(parts[j]);
            cnt++;
        }
        while (cnt < 3) {
            sum += 0.0;
            cnt++;
        }
        double media = sum / 3.0;

        alunos.push_back({nome, media});
    }

    stable_sort(alunos.begin(), alunos.end(), [](const auto& a, const auto& b) {
        if (fabs(a.second - b.second) > 1e-9) return a.second < b.second;
        return a.first < b.first;
    });

    cout.setf(std::ios::fixed);
    cout << setprecision(2);
    for (auto &p : alunos) {
        cout << p.first << " " << p.second + 1e-9 << "\n";
    }

    return 0;
}