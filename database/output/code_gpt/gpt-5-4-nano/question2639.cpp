/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long toLetter(const string& w) {
    long long sum = 0;
    for (unsigned char c : w) sum += (int)c;
    long long r = sum % 90;
    long long letter;
    if (r < 65) letter = 65 + (r % 26);
    else letter = r;
    return letter;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<string> words(N);
    for (int i = 0; i < N; i++) cin >> words[i];

    function<string(int)> solve = [&](int idx) -> string {
        if (idx == N) return "";
        long long letter = toLetter(words[idx]);
        string cur;
        cur.push_back((char)letter);
        return cur + solve(idx + 1);
    };

    string R = solve(0);
    cout << R;
    return 0;
}