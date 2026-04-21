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
    if (!(cin >> n)) return 0;
    string line;
    getline(cin, line);

    for (int i = 0; i < n; i++) {
        getline(cin, line);
        size_t l = 0, r = line.size();
        if (r == 0) {
            cout << "SIM\n";
            continue;
        }
        r--;

        while (l < line.size() && line[l] == ' ') l++;
        while (r < line.size() && line[r] == ' ' && r != string::npos) {
            if (r == 0) break;
            r--;
        }

        auto lowerChar = [](unsigned char c) -> char {
            return (char)tolower(c);
        };

        bool ok = true;
        l = 0; r = line.size() - 1;
        while (l < r) {
            while (l < line.size() && line[l] == ' ') l++;
            while (l < r && line[r] == ' ') r--;
            if (l >= r) break;

            if (lowerChar((unsigned char)line[l]) != lowerChar((unsigned char)line[r])) {
                ok = false;
                break;
            }
            l++; 
            if (r == 0) break;
            r--;
        }

        cout << (ok ? "SIM" : "NAO") << "\n";
    }
    return 0;
}