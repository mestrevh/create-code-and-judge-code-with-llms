/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool parsePortPair(const string& s, int& p1, int& p2) {
    size_t q1 = s.find('"');
    if (q1 == string::npos) return false;
    size_t colon = s.find(':', q1 + 1);
    if (colon == string::npos) return false;
    size_t q2 = s.find('"', colon + 1);
    if (q2 == string::npos) return false;
    string a = s.substr(q1 + 1, colon - (q1 + 1));
    string b = s.substr(colon + 1, q2 - (colon + 1));
    if (a.empty() || b.empty()) return false;
    p1 = stoi(a);
    p2 = stoi(b);
    return true;
}

static string extractQuoted(const string& line) {
    size_t q1 = line.find('"');
    if (q1 == string::npos) return "";
    size_t q2 = line.find('"', q1 + 1);
    if (q2 == string::npos) return "";
    return line.substr(q1 + 1, q2 - (q1 + 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<pair<int,int>, pair<long long,long long>> stats; 
    map<pair<int,int>, bool> open;
    map<pair<int,int>, long long> totalSent;
    map<pair<int,int>, long long> totalAcked;

    map<pair<int,int>, multiset<string>> pending;

    string line;
    while (true) {
        string s;
        if (!getline(cin, s)) break;
        if (s.empty()) continue;

        int p1, p2;
        if (s.find("hudpOpen") != string::npos) {
            if (!parsePortPair(s, p1, p2)) continue;
            pair<int,int> key = {p1, p2};
            if (!open[key]) {
                open[key] = true;
                pending[key].clear();
                totalSent[key] = 0;
                totalAcked[key] = 0;
            } else {
                if (!pending.count(key)) pending[key].clear();
            }
        } else if (s.find("hudpClose") != string::npos) {
            if (!parsePortPair(s, p1, p2)) continue;
            pair<int,int> key = {p1, p2};
            if (!open[key]) continue;
            open[key] = false;
        } else if (s.find("hudpSend") != string::npos) {
            if (!parsePortPair(s, p1, p2)) continue;
            pair<int,int> key = {p1, p2};
            if (!open[key]) continue;
            string msg = extractQuoted(s);
            if (msg.empty()) msg = "";
            pending[key].insert(msg);
            totalSent[key]++;
        } else if (s.find("ack") != string::npos) {
            int a1, a2;
            if (!parsePortPair(s, a1, a2)) continue;
            pair<int,int> key = {a2, a1}; 
            if (!open[key]) continue;
            string msg = extractQuoted(s);
            auto it = pending.find(key);
            if (it == pending.end()) continue;
            auto &ms = it->second;
            auto mit = ms.find(msg);
            if (mit != ms.end()) {
                ms.erase(mit);
                totalAcked[key]++;
            }
        }
    }

    vector<pair<pair<int,int>, pair<long long,long long>>> out;
    for (auto &kv : open) {
        pair<int,int> key = kv.first;
        if (!stats.count(key)) stats[key] = {0,0};
        long long sent = 0, acked = 0;
        if (totalSent.count(key)) sent = totalSent[key];
        if (totalAcked.count(key)) acked = totalAcked[key];
        long long loss = sent - acked;
        out.push_back({key, {acked, loss}});
    }
    sort(out.begin(), out.end(), [](auto &x, auto &y){
        if (x.first.first != y.first.first) return x.first.first < y.first.first;
        return x.first.second < y.first.second;
    });

    for (auto &e : out) {
        auto key = e.first;
        auto vals = e.second;
        cout << "\"" << key.first << ":" << key.second << "\""
             << " : " << vals.first << " ok : " << vals.second << " loss\n";
    }

    return 0;
}