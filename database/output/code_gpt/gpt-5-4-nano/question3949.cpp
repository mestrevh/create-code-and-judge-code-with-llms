/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Item {
    string name;
    double price = 0.0;
};

struct Market {
    int dist = 0;
    int m = 0;
    vector<Item> items;
    unordered_map<string, double> priceByName;
};

static inline string trim(const string& s) {
    size_t i = 0, j = s.size();
    while (i < j && isspace((unsigned char)s[i])) i++;
    while (j > i && isspace((unsigned char)s[j - 1])) j--;
    return s.substr(i, j - i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<Market> markets(N);

    for (int k = 0; k < N; k++) {
        int dist, m;
        cin >> dist >> m;
        markets[k].dist = dist;
        markets[k].m = m;
        markets[k].items.reserve(m);

        for (int i = 0; i < m; i++) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string line;
            getline(cin, line);
            line = trim(line);
            size_t dash = line.find('-');
            string name;
            string priceStr;
            if (dash != string::npos) {
                name = trim(line.substr(0, dash));
                priceStr = trim(line.substr(dash + 1));
            } else {
                name = trim(line);
                priceStr = "0";
            }
            double price = stod(priceStr);
            markets[k].items.push_back({name, price});
            markets[k].priceByName[name] = price;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int L;
    cin >> L;
    vector<string> wanted(L);
    for (int i = 0; i < L; i++) cin >> ws, getline(cin, wanted[i]);

    int bestIdx = 0;
    int bestCount = -1;
    int bestDist = INT_MAX;

    for (int k = 0; k < N; k++) {
        int cnt = 0;
        for (auto &w : wanted) {
            if (markets[k].priceByName.find(w) != markets[k].priceByName.end()) cnt++;
        }
        if (cnt > bestCount || (cnt == bestCount && markets[k].dist < bestDist)) {
            bestCount = cnt;
            bestDist = markets[k].dist;
            bestIdx = k;
        }
    }

    double total = 0.0;
    vector<pair<string,double>> bought;

    for (auto &w : wanted) {
        auto it = markets[bestIdx].priceByName.find(w);
        if (it != markets[bestIdx].priceByName.end()) {
            bought.push_back({w, it->second});
            total += it->second;
        }
    }

    cout << "Mercado: " << bestIdx << "\n";
    cout.setf(std::ios::fixed);
    cout << setprecision(2);
    for (auto &p : bought) {
        cout << p.first << " " << p.second << "\n";
    }
    cout << total << "\n";
    return 0;
}