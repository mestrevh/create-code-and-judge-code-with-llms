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
    while (N--) {
        int L;
        cin >> L;
        long long hash = 0;
        for (int i = 0; i < L; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < (int)s.size(); j++) {
                int posAlpha = s[j] - 'A';
                hash += posAlpha + i + j;
            }
        }
        cout << hash << "\n";
    }
    return 0;
}