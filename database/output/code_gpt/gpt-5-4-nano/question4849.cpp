/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static vector<string> extractWords(const string& s) {
    vector<string> words;
    string cur;
    for (unsigned char ch : s) {
        if (isalpha(ch)) {
            cur.push_back((char)ch);
        } else {
            if (!cur.empty()) {
                words.push_back(cur);
                cur.clear();
            }
        }
    }
    if (!cur.empty()) words.push_back(cur);
    return words;
}

static string normalizeWord(const string& w) {
    string t = w;
    for (char &c : t) c = (char)tolower((unsigned char)c);
    sort(t.begin(), t.end());
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line, s;
    if (!getline(cin, line)) return 0;
    s = line;
    while (getline(cin, line)) {
        if (!s.empty()) s += "\n";
        s += line;
    }

    vector<string> words = extractWords(s);

    unordered_map<string, vector<string>> mp;
    mp.reserve(words.size() * 2 + 1);

    for (const auto& w : words) {
        string key = normalizeWord(w);
        mp[key].push_back(w);
    }

    vector<pair<string,string>> pairs;
    for (auto &kv : mp) {
        auto &vec = kv.second;
        if (vec.size() < 2) continue;
        sort(vec.begin(), vec.end(), [](const string& a, const string& b){
            string la=a, lb=b;
            for(char &c:la) c=(char)tolower((unsigned char)c);
            for(char &c:lb) c=(char)tolower((unsigned char)c);
            if (la != lb) return la < lb;
            return a < b;
        });
        for (size_t i = 0; i < vec.size(); i++) {
            for (size_t j = i + 1; j < vec.size(); j++) {
                pairs.push_back({vec[i], vec[j]});
            }
        }
    }

    auto pairComp = [](const pair<string,string>& p1, const pair<string,string>& p2){
        string a1=p1.first, b1=p1.second, a2=p2.first, b2=p2.second;
        for(char &c:a1) c=(char)tolower((unsigned char)c);
        for(char &c:b1) c=(char)tolower((unsigned char)c);
        for(char &c:a2) c=(char)tolower((unsigned char)c);
        for(char &c:b2) c=(char)tolower((unsigned char)c);
        if (a1 != a2) return a1 < a2;
        if (b1 != b2) return b1 < b2;
        if (p1.first != p2.first) return p1.first < p2.first;
        return p1.second < p2.second;
    };

    sort(pairs.begin(), pairs.end(), pairComp);

    if (pairs.empty()) {
        cout << "Nao existem anagramas na frase.";
        return 0;
    }

    cout << "Pares de anagramas encontrados:\n";
    for (auto &p : pairs) {
        cout << p.first << " e " << p.second << "\n";
        cout << "\n";
        if (!cout.good()) break;
    }

    int total = (int)pairs.size();
    cout << "Total de pares: " << total;
    return 0;
}