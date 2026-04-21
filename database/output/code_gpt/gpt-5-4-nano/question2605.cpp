/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    string line;
    getline(cin, line);

    for (int i = 0; i < N; i++) {
        getline(cin, line);
        while (line.size() == 0 && i < N) getline(cin, line);

        vector<long long> a;
        long long x;
        stringstream ss(line);
        while (ss >> x) a.push_back(x);

        stable_sort(a.begin(), a.end());
        for (size_t j = 0; j < a.size(); j++) {
            if (j) cout << ' ';
            cout << a[j];
        }
        if (i + 1 < N) cout << "\n";
    }

    return 0;
}