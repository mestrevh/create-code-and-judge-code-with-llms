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

    vector<string> lines(N);
    for (int i = 0; i < N; i++) cin >> lines[i];

    string last;
    cin >> last;

    vector<long long> counts(256, 0);
    for (int i = 0; i < N; i++) {
        for (unsigned char ch : lines[i]) counts[ch]++;
    }

    for (unsigned char ch : last) {
        cout << ch << " = " << counts[ch] << "\n";
    }

    return 0;
}