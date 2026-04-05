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

    long long bal = 0;
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        for (char c : line) {
            if (c == '{') bal++;
            else if (c == '}') {
                if (bal == 0) {
                    cout << 'N';
                    return 0;
                }
                bal--;
            }
        }
    }

    cout << (bal == 0 ? 'S' : 'N');
    return 0;
}