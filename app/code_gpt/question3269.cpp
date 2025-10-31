/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<string> strings(N);
    for (int i = 0; i < N; i++) cin >> strings[i];

    map<string, int> prefixCount;

    for (const auto& s : strings) {
        string prefix;
        for (char c : s) {
            prefix += c;
            prefixCount[prefix]++;
        }
    }

    vector<string> result;
    for (const auto& [prefix, count] : prefixCount) {
        if (count >= K) result.push_back(prefix);
    }

    sort(result.begin(), result.end());
    
    cout << result.size() << endl;
    for (const auto& r : result) cout << r << endl;

    return 0;
}
