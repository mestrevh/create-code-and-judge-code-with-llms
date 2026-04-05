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

    vector<string> keys(n);
    string line;
    getline(cin, line);

    for (int i = 0; i < n; i++) {
        getline(cin, keys[i]);
        while (!keys[i].empty() && keys[i].back() == '\r') keys[i].pop_back();
        if (keys[i].empty()) {
            i--;
        }
    }

    string bits;
    if (!(cin >> bits)) bits = "";

    if (bits.empty()) {
        cout << "Sem bits no momento...";
        return 0;
    }

    long long sum = 0;
    for (size_t i = 0; i + 3 < bits.size(); i += 4) {
        int val = 0;
        for (int j = 0; j < 4; j++) {
            char c = bits[i + j];
            val = val * 2 + (c == '1' ? 1 : 0);
        }
        if (val > 9) cout << "Numero invalido!";
        sum += val;
    }

    vector<string> sortedKeys = keys;
    sort(sortedKeys.begin(), sortedKeys.end(), [](const string& a, const string& b){
        return a < b;
    });

    cout << "O codigo de entrada eh: " << sum;
    if (n == 0) {
        cout << "\n";
        return 0;
    }

    string senha;
    for (const string& k : sortedKeys) {
        cout << "\n" << k + to_string(sum);
    }
    return 0;
}