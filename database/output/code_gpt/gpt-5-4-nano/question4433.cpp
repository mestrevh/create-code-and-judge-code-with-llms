/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct TeamStats {
    string name;
    long long pts = 0;
    long long win = 0;
    long long draw = 0;
    long long lose = 0;
    long long gp = 0;
    long long gc = 0;
    long long sg = 0;
};

static bool isNumberToken(const string& s) {
    if (s.empty()) return false;
    int i = 0;
    if (s[0] == '-' || s[0] == '+') i = 1;
    if (i >= (int)s.size()) return false;
    for (; i < (int)s.size(); i++) if (!isdigit((unsigned char)s[i])) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    string dummy;
    getline(cin, dummy);

    unordered_map<string, TeamStats> mp;
    mp.reserve(2 * N + 5);

    auto getTeam = [&](const string& name) -> TeamStats& {
        auto it = mp.find(name);
        if (it == mp.end()) {
            TeamStats t;
            t.name = name;
            it = mp.emplace(name, t).first;
        }
        return it->second;
    };

    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        while(line.size() == 0 && !cin.eof()) getline(cin, line);
        stringstream ss(line);
        vector<string> tok;
        string w;
        while (ss >> w) tok.push_back(w);

        int firstNum = -1;
        for (int k = 0; k < (int)tok.size(); k++) {
            if (isNumberToken(tok[k])) {
                firstNum = k;
                break;
            }
        }

        string homeName, awayName;
        long long gh = 0, ga = 0;

        if (firstNum == -1) continue;

        for (int k = 0; k < firstNum; k++) {
            if (k) homeName += ' ';
            homeName += tok[k];
        }

        int secondNum = -1;
        for (int k = firstNum + 1; k < (int)tok.size(); k++) {
            if (isNumberToken(tok[k])) {
                secondNum = k;
                break;
            }
        }

        if (secondNum == -1) continue;

        gh = stoll(tok[firstNum]);

        for (int k = secondNum + 1; k < (int)tok.size(); k++) {
            if (isNumberToken(tok[k])) {
                ga = stoll(tok[k]);
                awayName.clear();
                for (int m = secondNum + 1; m < k; m++) {
                    if (m > secondNum + 1) awayName += ' ';
                    awayName += tok[m];
                }
                break;
            }
        }

        if (awayName.empty()) {
            for (int k = secondNum + 1; k < (int)tok.size(); k++) {
                if (k > secondNum + 1) awayName += ' ';
                awayName += tok[k];
            }
        }

        TeamStats& A = getTeam(homeName);
        TeamStats& B = getTeam(awayName);

        A.gp += gh; A.gc += ga;
        B.gp += ga; B.gc += gh;

        if (gh > ga) {
            A.win++; A.pts += 3;
            B.lose++;
        } else if (gh < ga) {
            B.win++; B.pts += 3;
            A.lose++;
        } else {
            A.draw++; A.pts += 1;
            B.draw++; B.pts += 1;
        }
    }

    vector<TeamStats> teams;
    teams.reserve(mp.size());
    for (auto &p : mp) teams.push_back(p.second);

    for (auto &t : teams) t.sg = t.gp - t.gc;

    sort(teams.begin(), teams.end(), [&](const TeamStats& a, const TeamStats& b) {
        if (a.pts != b.pts) return a.pts > b.pts;
        if (a.win != b.win) return a.win > b.win;
        if (a.sg != b.sg) return a.sg > b.sg;
        if (a.gp != b.gp) return a.gp > b.gp;
        return a.name < b.name;
    });

    for (int i = 0; i < (int)teams.size(); i++) {
        cout << (i + 1) << ". " << teams[i].name << ' '
             << teams[i].pts << ' '
             << teams[i].win << ' '
             << teams[i].draw << ' '
             << teams[i].lose << ' '
             << teams[i].gp << ' '
             << teams[i].gc << ' '
             << (teams[i].gp - teams[i].gc) << "\n";
    }

    return 0;
}