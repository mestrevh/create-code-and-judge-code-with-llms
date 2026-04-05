/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string toLowerStr(const string& s) {
    string r = s;
    for (char &c : r) c = (char)tolower((unsigned char)c);
    return r;
}

static inline bool isDigitChar(char c) { return c >= '0' && c <= '9'; }

static int parseDay(const string& line) {
    int i = 0;
    while (i < (int)line.size() && isDigitChar(line[i])) i++;
    if (i == 0) return 0;
    return stoi(line.substr(0, i));
}

static int parseYear(const string& line) {
    int n = (int)line.size();
    int i = n - 1;
    while (i >= 0 && !isDigitChar(line[i])) i--;
    int j = i;
    while (j >= 0 && isDigitChar(line[j])) j--;
    if (j == i) return 0;
    return stoi(line.substr(j + 1, i - j));
}

static string stripExtraSpaces(string s) {
    string out;
    bool inSpace = false;
    for (char c : s) {
        if (isspace((unsigned char)c)) {
            if (!inSpace) out.push_back(' ');
            inSpace = true;
        } else {
            out.push_back(c);
            inSpace = false;
        }
    }
    if (!out.empty() && out.front() == ' ') out.erase(out.begin());
    if (!out.empty() && out.back() == ' ') out.pop_back();
    return out;
}

static string parseMonthToken(const string& line) {
    string t = stripExtraSpaces(line);
    vector<string> parts;
    string cur;
    for (char c : t) {
        if (c == ' ') {
            if (!cur.empty()) {
                parts.push_back(cur);
                cur.clear();
            }
        } else cur.push_back(c);
    }
    if (!cur.empty()) parts.push_back(cur);
    if (parts.size() >= 3) return parts[2];
    return parts.empty() ? "" : parts[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    string dummy;
    getline(cin, dummy);

    struct Carta {
        int day;
        int year;
        string monthOriginal;
        string monthKey;
        string fromOriginal, toOriginal;
        string fromKey, toKey;
        string dateOriginal;
    };

    vector<Carta> cartas;
    cartas.reserve(N);

    for (int i = 0; i < N; i++) {
        Carta c;
        string lineDate;
        getline(cin, lineDate);
        while (lineDate.size() == 0 && !cin.eof()) getline(cin, lineDate);

        string from, to;
        getline(cin, from);
        getline(cin, to);

        c.day = parseDay(lineDate);
        c.year = parseYear(lineDate);
        c.monthOriginal = parseMonthToken(lineDate);
        c.monthKey = toLowerStr(c.monthOriginal);

        c.fromOriginal = from;
        c.toOriginal = to;
        c.fromKey = toLowerStr(from);
        c.toKey = toLowerStr(to);
        c.dateOriginal = stripExtraSpaces(lineDate);

        cartas.push_back(c);
    }

    unordered_map<string, int> monthNum;
    vector<string> months = {
        "janeiro","fevereiro","marco","março","abril","maio","junho","julho","agosto",
        "setembro","outubro","novembro","dezembro"
    };
    for (int i = 0; i < (int)months.size(); i++) {
        monthNum[months[i]] = (i / 1) % 12 + 1;
    }
    unordered_map<string,int> monthMap;
    monthMap["janeiro"] = 1;
    monthMap["fevereiro"] = 2;
    monthMap["março"] = 3;
    monthMap["marco"] = 3;
    monthMap["abril"] = 4;
    monthMap["maio"] = 5;
    monthMap["junho"] = 6;
    monthMap["julho"] = 7;
    monthMap["agosto"] = 8;
    monthMap["setembro"] = 9;
    monthMap["outubro"] = 10;
    monthMap["novembro"] = 11;
    monthMap["dezembro"] = 12;

    auto getMonthValue = [&](const string& mk)->int{
        auto it = monthMap.find(mk);
        if (it != monthMap.end()) return it->second;
        return 0;
    };

    sort(cartas.begin(), cartas.end(), [&](const Carta& a, const Carta& b) {
        int am = getMonthValue(a.monthKey);
        int bm = getMonthValue(b.monthKey);

        if (a.year != b.year) return a.year < b.year;
        if (am != bm) return am < bm;
        if (a.day != b.day) return a.day < b.day;
        if (a.fromKey != b.fromKey) return a.fromKey < b.fromKey;
        return a.toKey < b.toKey;
    });

    for (const auto& c : cartas) {
        cout << c.dateOriginal << "\n";
        cout << c.fromOriginal << "\n";
        cout << c.toOriginal << "\n";
    }

    return 0;
}