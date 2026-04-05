/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    int tc = 0;
    while ( (cin >> n) ) {
        if (n == 0) break;
        tc++;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        array<long long, 26> cnt{};
        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            for (unsigned char ch : line) {
                if (isalpha(ch)) {
                    char up = toupper(ch);
                    if (up >= 'A' && up <= 'Z') cnt[up - 'A']++;
                }
            }
        }
        
        vector<pair<int,long long>> v;
        v.reserve(26);
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) v.push_back({i, cnt[i]});
        }
        
        sort(v.begin(), v.end(), [](const auto& a, const auto& b){
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });
        
        cout << "TESTE " << tc << "\n";
        for (auto &p : v) {
            cout << char('A' + p.first) << " " << p.second << "\n";
        }
    }
    return 0;
}