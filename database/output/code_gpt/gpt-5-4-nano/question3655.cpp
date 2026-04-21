/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string processMusic(string s) {
    for (char &c : s) {
        if (c == '\r' || c == '\n' || c == '\t') c = ' ';
    }
    s.erase(remove(s.begin(), s.end(), '\n'), s.end());
    s.erase(remove(s.begin(), s.end(), '\r'), s.end());
    string noNewlines = s;

    string lowerProcessed;
    lowerProcessed.reserve(noNewlines.size());

    for (size_t i = 0; i < noNewlines.size(); i++) {
        char c = noNewlines[i];
        if (c == ' ') continue;
        if (c == 'a') lowerProcessed.push_back('@');
        else if (c == 'A') lowerProcessed.push_back('A');
        else if (c == 'E') lowerProcessed.push_back('%');
        else if (c == 'e') lowerProcessed.push_back('!');
        else if (c == 'i') lowerProcessed.push_back('@');
        else if (c == 'o') lowerProcessed.push_back('#');
        else if (c == 'u') lowerProcessed.push_back('$');
        else lowerProcessed.push_back(c);
    }
    return lowerProcessed;
}

static string capitalizeWordsOriginal(string original) {
    bool newWord = true;
    string s = original;
    for (char &c : s) {
        if (c == ' ') {
            newWord = true;
            continue;
        }
        if (newWord) {
            c = (char)toupper((unsigned char)c);
            newWord = false;
        } else {
            c = (char)tolower((unsigned char)c);
            newWord = false;
        }
    }
    return s;
}

static string transform(string music) {
    music = capitalizeWordsOriginal(music);
    string out;
    out.reserve(music.size());
    for (char c : music) {
        if (c == ' ') continue;
        if (c == 'a') out.push_back('@');
        else if (c == 'E') out.push_back('%');
        else if (c == 'e') out.push_back('!');
        else if (c == 'i') out.push_back('@');
        else if (c == 'o') out.push_back('#');
        else if (c == 'u') out.push_back('$');
        else out.push_back(c);
    }
    return out;
}

static string makePassword(const string &t, int idxMagic1Based, int numPasswordsCount) {
    int n = (int)t.size();
    int m = idxMagic1Based - 1;
    int neededLen = 5 + 5 + 5;
    int maxStartFirst = numPasswordsCount - 1;
    int startFirst = maxStartFirst;
    int startNext = m + 1;
    string temp;
    temp.reserve(15);

    for (int i = 0; i < 5; i++) {
        int pos = startFirst + i;
        if (pos >= 0 && pos < n) temp.push_back(t[pos]);
        else temp.push_back('?');
    }
    for (int i = 0; i < 5; i++) {
        int pos = m + i;
        if (pos >= 0 && pos < n) temp.push_back(t[pos]);
        else temp.push_back('?');
    }
    for (int i = 0; i < 5; i++) {
        int pos = startNext + i;
        if (pos >= 0 && pos < n) temp.push_back(t[pos]);
        else temp.push_back('?');
    }

    if ((int)temp.size() != 15) temp.resize(15, '?');
    reverse(temp.begin(), temp.end());
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line, music;
    bool gotMusic = false;

    vector<string> inputs;
    while (true) {
        string s;
        if (!getline(cin, s)) break;
        if (s.size() && s.back() == '\r') s.pop_back();
        inputs.push_back(s);
    }

    if (inputs.empty()) return 0;

    int k = (int)inputs.size();
    int i = 0;

    vector<string> musicParts;
    while (i < k) {
        string s = inputs[i];
        if (!gotMusic) {
            musicParts.push_back(s);
            i++;
            if (i < k) {
                bool nextIsInt = !inputs[i].empty();
                for (char c : inputs[i]) {
                    if (!isdigit((unsigned char)c) && c!='-' && c!='+') { nextIsInt = false; break; }
                    if (isdigit((unsigned char)c)) { nextIsInt = true; }
                }
                if (nextIsInt) {
                    gotMusic = true;
                    break;
                }
            }
        } else break;
    }

    music.clear();
    for (size_t j = 0; j < musicParts.size(); j++) {
        if (j) music.push_back(' ');
        music += musicParts[j];
    }

    vector<long long> nums;
    while (i < k) {
        string s = inputs[i++];
        if (s.size() == 0) continue;
        bool ok = true;
        for (char c : s) if (!isdigit((unsigned char)c) && c!='-' && c!='+') ok = false;
        if (ok) {
            nums.push_back(stoll(s));
        } else {
            inputs.push_back(""); 
        }
    }

    // Re-parse properly from original stream-like:
    // Approach: use regex-like splitting from the stored lines:
    // music is all lines before the first pure integer line.
    // Remaining lines contain: q, (for each user: x acceptFlag then username). But statement: q then number between 6..len-6, then S/N, then username.
    // We'll re-parse remaining tokens in order: q, then for each: idx, ans, username.
    // Use stored lines from where first integer begins.
    size_t posFirstInt = 0;
    {
        int ii = 0;
        while (ii < (int)inputs.size()) {
            string s = inputs[ii];
            bool ok = !s.empty();
            for (char c : s) {
                if (!isdigit((unsigned char)c) && c!='-' && c!='+') { ok = false; break; }
            }
            if (ok) { posFirstInt = ii; break; }
            ii++;
        }
    }

    // Better: Determine idx of first integer line based on how we built musicParts
    // Since we split earlier, the index i used after loop points to the first integer line.
    // But we lost it due to reprocessing; we should recompute i.
    {
        // Recompute based on musicParts count: first integer line is at index = musicParts.size() (from reading) - but only if music was on single line.
        // We'll recompute using same method as earlier but simpler:
    }

    // Let's reconstruct deterministically:
    // We will use the original inputs vector, find first line that is purely integer.
    size_t firstIntIdx = 0;
    for (size_t t = 0; t < inputs.size(); t++) {
        string s = inputs[t];
        if (s.empty()) continue;
        bool ok = true;
        size_t cntDigit = 0;
        size_t st = 0;
        if (s[0]=='-' || s[0]=='+') st = 1;
        for (size_t j = st; j < s.size(); j++) {
            if (!isdigit((unsigned char)s[j])) { ok = false; break; }
            cntDigit++;
        }
        if (ok && cntDigit>0) { firstIntIdx = t; break; }
    }

    music = "";
    for (size_t t = 0; t < firstIntIdx; t++) {
        if (t) music.push_back(' ');
        music += inputs[t];
    }

    vector<string> rest = {};
    for (size_t t = firstIntIdx; t < inputs.size(); t++) rest.push_back(inputs[t]);

    auto isIntLine = [&](const string &s)->bool{
        if (s.empty()) return false;
        size_t st = 0;
        if (s[0]=='-' || s[0]=='+') st = 1;
        if (st==s.size()) return false;
        for (size_t j = st; j < s.size(); j++) if (!isdigit((unsigned char)s[j])) return false;
        return true;
    };

    int q = 0;
    size_t rp = 0;
    while (rp < rest.size() && rest[rp].empty()) rp++;
    if (rp >= rest.size()) return 0;
    q = stoi(rest[rp++]);

    vector<pair<string,string>> accepted;
    string transformed = transform(music);
    int L = (int)transformed.size();

    for (int caseNo = 0; caseNo < q; caseNo++) {
        while (rp < rest.size() && rest[rp].empty()) rp++;
        int idxMagic = stoi(rest[rp++]);
        while (rp < rest.size() && rest[rp].empty()) rp++;
        string ans = rest[rp++];
        while (rp < rest.size() && rest[rp].empty()) rp++;
        string username = rest[rp++];

        if (!ans.empty() && (ans[0]=='S' || ans[0]=='s')) {
            int magic = idxMagic;
            int countPasswordsGenerated = q;
            string pass;
            if (caseNo < countPasswordsGenerated) {
                pass = makePassword(transformed, magic, countPasswordsGenerated);
            } else {
                pass = makePassword(transformed, magic, countPasswordsGenerated);
            }
            accepted.push_back({username, pass});
        } else {
            int magic = idxMagic;
            int countPasswordsGenerated = q;
            string pass = makePassword(transformed, magic, countPasswordsGenerated);
            (void)pass;
        }
    }

    cout << "{";
    for (size_t i2 = 0; i2 < accepted.size(); i2++) {
        if (i2) cout << ", ";
        cout << "'" << accepted[i2].first << "': '" << accepted[i2].second << "'";
    }
    cout << "}";
    return 0;
}