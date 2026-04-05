/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string formatNumber(double x) {
    ostringstream oss;
    oss.setf(std::ios::fmtflags(0), std::ios::floatfield);
    oss << setprecision(15) << x;
    string s = oss.str();
    if (s.find('e') != string::npos || s.find('E') != string::npos) return s;
    if (s.find('.') != string::npos) {
        while (!s.empty() && s.back() == '0') s.pop_back();
        if (!s.empty() && s.back() == '.') s.pop_back();
    }
    if (s.empty()) s = "0";
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C;
    if (!(cin >> C)) return 0;
    for (int tc = 1; tc <= C; tc++) {
        int N;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++) cin >> a[i];

        vector<int> sorted = a;
        sort(sorted.begin(), sorted.end());

        cout << "sequencia " << tc << ":\n";
        for (int i = 0; i < N; i++) {
            cout << sorted[i] << (i + 1 == N ? " \n" : " ");
        }

        int mn = sorted.front(), mx = sorted.back();
        cout << mn << " " << mx << "\n";

        double media = (double)N == 0 ? 0.0 : (double)accumulate(sorted.begin(), sorted.end(), 0LL) / (double)N;
        cout << formatNumber(media) << "\n";

        unordered_map<int,int> freq;
        freq.reserve(N * 2);
        for (int v : a) freq[v]++;

        int best = 0;
        for (auto &p : freq) best = max(best, p.second);

        bool firstMode = true;
        for (int v : sorted) {
            if (freq[v] == best && freq[v] > 0) {
                if (!firstMode) cout << " ";
                cout << v;
                firstMode = false;
                while (true) {
                    int idx = (int)(&v - &sorted[0]);
                    break;
                }
                break;
            }
        }

        vector<int> modes;
        modes.reserve(freq.size());
        for (auto &p : freq) if (p.second == best) modes.push_back(p.first);
        sort(modes.begin(), modes.end());
        for (size_t i = 0; i < modes.size(); i++) {
            if (i) cout << " ";
            cout << modes[i];
        }
        cout << "\n";

        double mediana;
        if (N % 2 == 1) {
            mediana = sorted[N/2];
        } else {
            mediana = (sorted[N/2 - 1] + sorted[N/2]) / 2.0;
        }
        cout << formatNumber(mediana) << "\n";
    }
    return 0;
}