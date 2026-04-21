/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
bool is_p[MAXN];
bool is_ap[MAXN];
vector<int> ps;

void pre() {
    for (int i = 2; i < MAXN; i++) is_p[i] = true;
    for (int i = 2; i < MAXN; i++) {
        if (is_p[i]) {
            ps.push_back(i);
            for (long long j = 1LL * i * i; j < MAXN; j += i)
                is_p[j] = false;
        }
    }
    for (int i = 0; i < (int)ps.size(); i++) {
        for (int j = i + 1; j < (int)ps.size(); j++) {
            long long prod = 1LL * ps[i] * ps[j];
            if (prod >= (long long)MAXN) break;
            is_ap[(int)prod] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        if (!(cin >> n)) break;
        if (n >= 1 && n < MAXN) {
            if (is_p[n]) {
                cout << "Primo\n";
            } else if (is_ap[n]) {
                cout << "Quase primo\n";
            } else {
                cout << "Nem primo nem quase primo\n";
            }
        } else {
            cout << "Nem primo nem quase primo\n";
        }
    }
    return 0;
}